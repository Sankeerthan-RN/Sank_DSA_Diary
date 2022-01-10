class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int ans=1;
        while(!q.empty())
        {
            int sz=q.size();
            int leftmin=q.front().second;
            ans=max(ans, (q.back().second-q.front().second)+1 );
            while(sz--)
            {
                TreeNode*node=q.front().first;
                int idx=q.front().second-leftmin;
                q.pop();
                if(node->left)
                {
                    q.push({node->left,2*idx+1});
                }
                if(node->right)
                {
                     q.push({node->right,2*idx+2});
                }
            }
        }
        return ans;
    }
};
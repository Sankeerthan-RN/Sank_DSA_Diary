/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       
        if(!root)return {};
        stack<TreeNode*>s;
        s.push(root);
        vector<vector<int>>res;
        int cnt=0;
        while(!s.empty())
        {
            vector<int>ans;
            int sz=s.size();
            stack<TreeNode*>p;
            cnt++;
            while(sz--)
            {
                auto x=s.top();
                ans.push_back(x->val);
                s.pop();
                if(cnt%2==0)
                {
                     if(x->right)p.push(x->right);
                     if(x->left)p.push(x->left);
                }
                else{
                     if(x->left)p.push(x->left);
                     if(x->right)p.push(x->right);
                }
               
                
                
            }
           
            s=p;
            res.push_back(ans);
        }
        return res;
    }
};

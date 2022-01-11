class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)return 0;
        int depth=max(maxDepth(root->left),maxDepth(root->right))+1;
        return depth;
        
    }
};

/////////////////////////////////////////////////

class Solution {
public:
    int maxDepth(TreeNode *root)
{
    if(root == NULL)
        return 0;
    
    int cnt = 0;
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty())
    {
        cnt++;
        for(int i = 0, n = q.size(); i < n; ++ i)
        {
            auto *p = q.front();
            q.pop();
            
            if(p -> left != NULL)
                q.push(p -> left);
            if(p -> right != NULL)
                q.push(p -> right);
        }
    }
    
    return cnt;
}
};
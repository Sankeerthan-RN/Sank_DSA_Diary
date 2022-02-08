class Solution  {
    
private:
    void sol(TreeNode* root)
    {
        if(root==NULL)return;
        sol(root->right);
        sol(root->left);
        root->left=NULL;
        root->right=pre;
        pre=root;
        return;
    }
        
        
public:
    
    TreeNode*pre=NULL;
    void flatten(TreeNode* root) {
        sol(root);
        return;
    }
};

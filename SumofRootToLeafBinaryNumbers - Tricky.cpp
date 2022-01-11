class Solution {
    
private:
    void sol(TreeNode*  root,int ans)
    {
        
         ans=(ans<<1)+root->val;
         if(root->left==NULL && root->right==NULL)
         {
             res+=ans;
         }
        
        if(root->left)sol(root->left, ans);
        if(root->right)sol(root->right,ans);
        
        
     
           
    }
public:
    int res=0;
    int sumRootToLeaf(TreeNode* root) {
        sol(root,0);
        return res;
    }
};
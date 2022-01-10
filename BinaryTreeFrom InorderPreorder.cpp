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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        map<int,int>mp;
        int i=0;
        for(auto x:inorder)
        {
            mp[x]=i;
            i++;
        }
        int end=inorder.size()-1;
        return Inpre(0,end,0,end,mp,preorder,inorder);
    }
    
    TreeNode* Inpre(int prestart,int preend ,int  instart,int inend ,map<int,int>&mp,vector<int>& preorder, vector<int>& inorder)
    {
        
        
         if(prestart>preend || instart>inend)return NULL;
        
         
           TreeNode* node= new TreeNode(preorder[prestart]);
        
           int inordernum= mp[preorder[prestart]];
           int numsleft= inordernum-instart;  
        
        
       node->left=Inpre(prestart+1,prestart+numsleft,instart ,inordernum-1,mp,preorder,inorder);
       node->right=Inpre(prestart+numsleft+1,preend,inordernum+1,inend,mp,preorder,inorder);
            
        return node;    
        
    }
};
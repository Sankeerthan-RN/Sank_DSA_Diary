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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
             
        map<int,int>mp;
        int i=0;
        for(auto x:inorder)
        {
            mp[x]=i;
            i++;
        }
        int end=inorder.size()-1;
        
        return Inpos(0,end,0,end,mp,inorder,postorder);
    }
    
    TreeNode*Inpos(int instart,int inend,int postart,int posend,map<int,int>&mp,vector<int>&inorder,vector<int>&postorder)
    {
        
        if(instart>inend || postart>posend)return NULL;
        TreeNode* node = new TreeNode(postorder[posend]);
        int inordernum = mp[postorder[posend]];
        int numsleft  =inend -inordernum;
        
        node->left= Inpos(instart,inordernum-1,postart,posend-numsleft-1,mp,inorder,postorder);
        node->right= Inpos(instart+1,inend,posend-numsleft,posend-1,mp,inorder,postorder);
        return node;
    }
};
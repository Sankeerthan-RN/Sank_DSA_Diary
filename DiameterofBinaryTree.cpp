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
    int sol(TreeNode* root,int& maxdepth)
    {
        if(root==NULL)return 0;
        int left =sol(root->left,maxdepth);
        int right =sol(root->right,maxdepth);
        maxdepth=max(maxdepth,left+right);
        return max(left,right)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxdepth=0;
        sol (root,maxdepth);
        return maxdepth;
    }
};
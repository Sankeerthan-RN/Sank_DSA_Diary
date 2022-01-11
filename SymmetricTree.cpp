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
    
private:
    bool sol(TreeNode*node1,TreeNode* node2)
    {
          if(node1==NULL && node2==NULL)return true;
          if(node1==NULL || node2==NULL)return false;
          if(node1->val!=node2->val)return false;
          return (sol(node1->right,node2->left) && sol(node1->left,node2->right));
    }
public:
    bool isSymmetric(TreeNode* root) {
         return sol(root->left,root->right);
        }
        
    
};
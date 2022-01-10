/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool sol(TreeNode* node,int target, vector<int>&ans)
{

    if(!node)return false;
    
    if(node->val==target)
    {   ans.push_back(target);
        return true;
    }

    if(sol(node->left,target,ans) || sol(node->right,target,ans))
    {
        ans.push_back(node->val);
        return true;
    }

    return false;


}
vector<int> Solution::solve(TreeNode* A, int B) {

        vector<int>ans;
        sol(A,B,ans);
        reverse(ans.begin(),ans.end());
        return ans;
}

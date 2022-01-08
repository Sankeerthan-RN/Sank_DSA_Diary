class Solution {
    vector<int>ans;
    stack<TreeNode*>s;
public:
    vector<int> inorderTraversal(TreeNode* root) {
       
        TreeNode *curr=root;
        while(true)
        {
            if(curr)   
            {
            s.push(curr);
            curr=curr->left;
            }
            else{
                if(s.empty())break;
                ans.push_back(s.top()->val);
                
                curr=s.top()->right;
                s.pop();
            }
        }
        return ans;
    }
};
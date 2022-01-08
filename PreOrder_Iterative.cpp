   stack<TreeNode*>s;
    vector<int>ans;
    vector<int> preorderTraversal(TreeNode* root) {
        
        TreeNode *curr=root;
        while(true)
        {
            if(curr)   
            {
            ans.push_back(curr->val);
            s.push(curr);
            curr=curr->left;
            }
            else{
                if(s.empty())break;
                curr=s.top()->right;
                s.pop();
            }
        }
        return ans;
    }
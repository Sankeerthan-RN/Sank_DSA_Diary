void sol(Node *root,int level ,vector<int> &ans)
    {
           
             if(root==NULL)return;
             if(ans.size()==level)ans.push_back(root->data);
             sol(root->left,level+1,ans);
             sol(root->right,level+1,ans);
             return;
             
    }
vector<int> leftView(Node *root)
{
  vector<int>res;
  sol(root,0,res);
  return res;
}

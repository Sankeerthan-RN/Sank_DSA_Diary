class Solution {
  public:
  
    map<int,int>mp;
    queue<pair<Node*,int>>q;
    vector<int>ans;
    
    vector <int> bottomView(Node *root) {
        
            q.push({root,0});
            
               while(!q.empty())
               {
                   Node* top=q.front().first;
                   int level=q.front().second;
                   q.pop();
                   mp[level]=top->data;
                   if(top->left)q.push({top->left,level-1});
                   if(top->right)q.push({top->right,level+1});
               }
               
                for(auto it : mp) {
                    ans.push_back(it.second); 
                }
                return ans;
               
    }
};

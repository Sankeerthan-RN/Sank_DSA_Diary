class Solution
{
 
  bool sub(Node* t,Node * s)
  {
      if(s==NULL)return true;
      if(t==NULL)return false;
      
      if(sameTree(t,s))return true;
      
      return(  sub(t->left,s) or sub(t->right,s) );
      
  }
  bool sameTree(Node* x,Node * y)
  {
      if(x==NULL && y==NULL)return true;
      if(x==NULL || y==NULL)return false;
      if(x->data ==y->data) 
      {
          return (sameTree(x->left,y->left) && sameTree(x->right,y->right));
      }
      return false;
 }
    
  public:
    queue<Node* >q;
    bool isSubTree(Node* T, Node* S) 
    {
       return  sub(T,S);
       
        
    }
};

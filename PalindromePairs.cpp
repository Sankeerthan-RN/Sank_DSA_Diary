//palindrome Pair
//https://practice.geeksforgeeks.org/problems/palindrome-pairs/1


class Solution{  
    
    
 public:
    
    bool isPalindrome(string x)
    {
        int r=x.length()-1;
        int l=0;
        while(l<=r)
        {
            if(x[l]!=x[r])return 0;
            l++;
            r--;
        }
        return 1 ;
    }
    
  public:
    // Function to check if a palindrome pair exists
    bool palindromepair(int n, string arr[]) {
        map<string,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]=i;
        }
        
       
        for(int j=0;j<n;j++)
        {
            string s=arr[j];
            
            for(int i=0;i<s.length();i++)
            {
                string left=s.substr(0,i);
                string right=s.substr(i);
                
                if(isPalindrome(left))
                {
                    reverse(right.begin(),right.end());
                    if(mp.find(right)!=mp.end())
                    {
                       
                        if(mp[right]!=j)
                        {
                             
                            return 1;
                        }
                    }
                   
                }
                
                if(isPalindrome(right))
                {
                    reverse(left.begin(),left.end());
                   
                    if(mp.find(left)!=mp.end())
                    {
                        if(mp[left]!=j)
                        {
                             
                            return 1;
                        }
                    }
                }
            }
            
            // string temp=s;
            // reverse(temp.begin(),temp.end());
            // if(mp[temp])return 1;
        }
        return 0;
        
        
    }

};

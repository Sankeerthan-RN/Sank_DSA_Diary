//https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int>mp;
        
        int len=INT_MAX;
        int  matched=0;
        int start=0,substart=0;
        
        for(auto x: t)mp[x]++;
        
        for(int i=0;i<s.length();i++)
        {
            char right=s[i];
            if(mp.find(right)!=mp.end())
            {
                
                 mp[right]--;
                if(mp[right]>=0)
                {
                    matched++;
                }
                
              
            }
            
            
            while(matched==t.length())
            {
                
                
            
                if(len>i-start+1)
                {
                substart=start;
                len=i-start+1;
              
                }
                  char left=s[start++];
                 
                
                if(mp.find(left)!=mp.end())
                {
                    if(mp[left]==0)matched--;
                     mp[left]++;
                }
                
               
            }
            
           
            
            
            
        }
        
        return (len>s.length()) ? "" : s.substr(substart,len);
      
    }
};
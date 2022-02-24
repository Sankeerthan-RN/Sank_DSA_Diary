
//https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1#
class Solution{
  public:
    int longestKSubstr(string s, int k) {
        
    map<char,int>mp;    
    int start=0,maxi=-1,n=s.length();
    for(int i=0;i<n;i++)
    {
        mp[s[i]]++;
        while(mp.size()>k)
        {
            mp[s[start]]--;
            
            if(mp[s[start]]==0)mp.erase(s[start]);
            
            start++;
        }
        if(mp.size()==k) maxi=max(maxi,i-start+1);
       
       
    }
    return maxi;
    
    }
};
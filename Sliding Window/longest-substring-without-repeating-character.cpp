
//https://leetcode.com/problems/longest-substring-without-repeating-character
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int maxi=0,start=0;
        map<char,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
            while(mp.size()<(i-start)+1) 
            {
                mp[s[start]]--;
                if(mp[s[start]]==0)mp.erase(s[start]);
                start++;
            }
            maxi=max(maxi,i-start+1);
            
        }
        return maxi;
    }
};
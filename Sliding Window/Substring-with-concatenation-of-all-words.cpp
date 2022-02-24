

//https://leetcode.com/problems/substring-with-concatenation-of-all-words/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
      
      map<string,int>mp;
      vector<int>ans;  
      for(auto x: words)mp[x]++;  
      int wordlen=words[0].size();
      int totalsize=wordlen*words.size(); 
      int sz=s.length();  
      for(int i=0;i<=sz-totalsize;i++)
      {
          map<string,int>k;
          for(int j=0;j<words.size();j++)
          {
              
              int idx=i+j*wordlen;
              string sub=s.substr(idx,wordlen);
              if(mp.find(sub)==mp.end())
              {
                 break;
              }
              k[sub]++;
              if(mp[sub]<k[sub])
              {
                  break;
              }
              
              if(k==mp)ans.push_back(i);
          }
      }
        return ans;
        
        
    }
};
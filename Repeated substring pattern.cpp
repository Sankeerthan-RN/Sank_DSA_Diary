https://leetcode.com/problems/repeated-substring-pattern/

class Solution {
public:
    vector<int> kmp_algo(string s){
        int len=0, i=1, n=s.size();
        vector<int> kmp(n,0);
        while(i<n){
            if(s[i]==s[len]){
                kmp[i]=len+1;
                i++;
                len++;
            }else{
                if(len!=0){
                    len=kmp[len-1];
                }else{
                    kmp[i]=0;
                    ++i;
                }
            }
        }
        return kmp;
    }
    
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        auto kmp = kmp_algo(s);
        
        int len = n-kmp[n-1];
        if(kmp[n-1]%len == 0 && kmp[n-1]!=0) return true;
        return false;
    }
};
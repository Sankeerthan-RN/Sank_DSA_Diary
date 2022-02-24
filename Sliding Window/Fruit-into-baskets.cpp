//https://leetcode.com/problems/fruit-into-baskets/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int>mp;
        int maxi=0,sum=0,start=0;
        for(int i=0;i<fruits.size();i++)
        {
            mp[fruits[i]]+=1;
            sum+=1;
            while(mp.size()>2)
            {
                mp[fruits[start]]-=1;
                sum-=1;
                
                if(mp[fruits[start]]==0)mp.erase(fruits[start]);
                start++;
            }
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};
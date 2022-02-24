//https://leetcode.com/problems/target-sum/

class Solution {
    
int sum;
vector<vector<int>>dp;   
int tar=0;    
    
public:
    int sol(int n,int val,vector<int>& nums)
    {
        if(n<0)
        {
            if(val-(sum-val)==tar)return 1;
            else return 0;
        }
        
        if(dp[n][val]!=-1)return dp[n][val];
        int pick=0;
        if(val-nums[n]>=0)
        {
            pick=sol(n-1,val-nums[n],nums);
        }
        int nopick=sol(n-1,val,nums);
        
        return dp[n][val]=pick+nopick;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        sum=0;
        tar=target;
        int n=nums.size();
        for(auto x: nums)sum+=x;
        dp.resize(n+1,vector<int>(sum+1,-1));
        return sol(n-1,sum,nums);
    }
};
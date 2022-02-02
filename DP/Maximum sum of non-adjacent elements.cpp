//https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261
#include<bits/stdc++.h>

int sol(int i ,vector<int>&nums,vector<int>&dp)
{
    if(i<0)return 0;
    if(dp[i]!=-1)return dp[i];
    int sum=INT_MIN;
    sum=max(sol(i-2,nums,dp)+nums[i],sol(i-1,nums,dp));
    return dp[i]=sum;
}

int maximumNonAdjacentSum(vector<int> &nums){
    
    int n=nums.size();
    vector<int >dp(n+1,-1);
    return sol(n-1,nums,dp);
}
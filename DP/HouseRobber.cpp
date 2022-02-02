//https://www.codingninjas.com/codestudio/problems/house-robber_839733
#include<bits/stdc++.h>
typedef long long int ll;
ll sol(int i ,vector<int>&nums,vector<ll>&dp)
{
    if(i<0)return (ll) 0;
    if(dp[i]!=-1)return dp[i];
    ll sum=(ll)-1;
    sum=max(sol(i-2,nums,dp)+nums[i],sol(i-1,nums,dp));
    return dp[i]=sum;
}




long long int houseRobber(vector<int>& house)
{
    int n=house.size();
    vector<ll>dp(n+1,-1);
     vector<int>temp1(n+1,0);
     vector<int>temp2(n+1,0);
    for(int i=0;i<n;i++)
    {
         if(i!=0)temp1[i]=(house[i]);
         if(i!=n-1)temp2[i]=(house[i]);
    }
    ll first=sol(n-1,temp1,dp);
    ll last =sol(n-1,temp2,dp);
    return (max(first,last));
}
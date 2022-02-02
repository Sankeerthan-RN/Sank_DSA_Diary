//https://atcoder.jp/contests/dp/tasks/dp_b
#include <bits/stdc++.h>
 
using namespace std;
 
int sol(int i , int k, vector<int>&v,vector<int>&dp)
{
    
    if(i==0)return 0;
    if(dp[i]!=-1)return dp[i];
    int ans=INT_MAX;
    for(int j=1;j<=k;j++)
    {
        if(i-j>=0) ans=min(ans,sol(i-j,k,v,dp)+abs(v[i]-v[i-j]));
       
    }
    return dp[i]=ans;
}
 
int main()
{
    int n,k;  
    cin>>n>>k;
    vector<int>v(n+1);
    vector<int>dp(n+1,-1);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<sol(n-1,k,v,dp);
    return 0;
}
//https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003
#include<bits/stdc++.h>
int sol(int n,vector<vector<int>> &points,vector<vector<int>> &dp)
{
    dp[0][0]=points[0][0];
    dp[0][1]=points[0][1];
    dp[0][2]=points[0][2];
    
    for(int i=1;i<=n-1;i++)
    {
        for(int prev=0;prev<3;prev++)
        {
            dp[i][prev]=0;
            for(int curr=0;curr<3;curr++)
            {
                if(curr!=prev)
                {
                    int point=dp[i-1][curr]+points[i][prev];
                    dp[i][prev]=max(point,dp[i][prev]);
                }
                 
           }
            
        }
  
    }
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(n+1,vector<int>(4,0));
    sol(n,points,dp);
    return max(dp[n-1][0], max(dp[n-1][1],dp[n-1][2]));
}
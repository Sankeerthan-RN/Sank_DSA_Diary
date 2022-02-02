//https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003
#include<bits/stdc++.h>
int sol(int i,int task,vector<vector<int>> &points,vector<vector<int>> &dp)
{
    if(i<0)return 0;
    if(dp[i][task]!=-1)return dp[i][task];
     int maxi=0;
    for(int k=0;k<3;k++)
    {
        if(task!=k)
        {
            
            maxi= max(maxi,sol(i-1,k,points,dp)+points[i][k]);
        }
    }
    return dp[i][task]=maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(n+1,vector<int>(4,-1));
    return sol(n-1,3,points,dp);
}
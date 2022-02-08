
//https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494
#include<bits/stdc++.h>
int minSubsetSumDifference(vector<int>& arr, int n)
{
    int sum =0;
    for(auto x: arr)sum+=x;
	vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
    for(int i=0;i<n;i++)dp[i][0]=1;
    if(arr[0]<=sum)dp[0][arr[0]]=1;
    
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            
            int nopick=dp[i-1][j];
            int pick=0;
            if(arr[i]<=j)pick=dp[i-1][j-arr[i]];
            dp[i][j]=pick||nopick;
        }
    }
    int mini=INT_MAX;
    for(int i=0;i<=sum;i++)
    {
        if(dp[n-1][i])
        {
                int diff=abs(sum-i);
        	 mini=min(mini,abs(diff-i));
        }
       
    }
    return mini;
    
}

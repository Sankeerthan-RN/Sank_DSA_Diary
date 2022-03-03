//https://www.codingninjas.com/codestudio/problems/matrix-chain-multiplication

int sol( int i ,int j,vector<int>&arr ,vector<vector<int>>&dp)
{
    if(i==j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int mini=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int steps=arr[i-1]*arr[k]*arr[j];
        steps+=sol(i,k,arr,dp)+sol(k+1,j,arr,dp);
        mini=min(mini,steps);
    }
    return dp[i][j]=mini;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>>dp(N+1,vector<int>(N+1,-1));
   return sol(1,N-1,arr,dp);
}
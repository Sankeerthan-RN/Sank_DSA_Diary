//https://www.codingninjas.com/codestudio/problems/matrix-chain-multiplication

int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>>dp(N+1,vector<int>(N+1,0));
    for(int i=0;i<N;i++)dp[i][i]=0;
    int i,j;
    for( i=N-1;i>=1;i--)
    {
      
        for(j=i+1;j<=N-1;j++)
        {
              int mini=INT_MAX;
             for(int k=i;k<j;k++)
            {
                int steps=arr[i-1]*arr[k]*arr[j];
                steps+=dp[i][k]+dp[k+1][j];
                mini=min(mini,steps);
            }
             dp[i][j]=mini;
             
        }
       
       
    }
  return dp[1][N-1];
}
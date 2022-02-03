//https://www.codingninjas.com/codestudio/problems/total-unique-paths
int row;
int col;
int sol(int i,int j,vector<vector<int>>&dp)
{
    if(i>=row || j>=col)return 0;
    if(i==row-1 && j==col-1)return 1;
    if(dp[i][j]!=-1)return dp[i][j];
    
    return dp[i][j]=sol(i,j+1,dp)+sol(i+1,j,dp);
}

int uniquePaths(int m, int n) {
    vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
    row=m;
    col=n;
   return sol(0,0,dp);
}
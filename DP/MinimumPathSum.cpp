
//https://leetcode.com/problems/minimum-path-sum/
class Solution {            
public:
    int sol(int i ,int j, vector<vector<int>>&grid ,vector<vector<int>>& dp)
    {
        if(i<0 || j<0)return 1e7;
        if(i==0 && j==0)return grid[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=min(sol(i-1,j,grid,dp)+grid[i][j] ,  sol(i,j-1,grid,dp)+grid[i][j]);
        
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m=grid.size()-1;
        int n=grid[0].size()-1;
        
        vector<vector<int>>dp(m+2,vector<int>(n+2,-1));
        return sol(m,n,grid,dp);
        
    }
};
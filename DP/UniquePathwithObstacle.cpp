https://leetcode.com/problems/unique-paths-ii/class Solution {
    
    
    
public:
    int sol(int i ,int j, vector<vector<int>>&obj ,vector<vector<int>>& dp)
    {
        if(i<0 || j<0)return 0;
        if(obj[i][j]==1)return 0;
        if(i==0 && j==0)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=sol(i-1,j,obj,dp)+sol(i,j-1,obj,dp);
        
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size()-1;
        int n=obstacleGrid[0].size()-1;
        
        vector<vector<int>>dp(m+2,vector<int>(n+2,-1));
        if(obstacleGrid[m][n]==1)return 0;
        return sol(m,n,obstacleGrid,dp);
    }
};
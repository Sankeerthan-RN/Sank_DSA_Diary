//https://leetcode.com/problems/triangle/
class Solution {
public:
int sol(int i ,int j, vector<vector<int>>&grid ,vector<vector<int>>& dp)
    {
        if(i>=m)return 1e7;
        if(i==m-1) return grid[i][j];
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        return dp[i][j]=min(sol(i+1,j,grid,dp)+grid[i][j] ,  sol(i+1,j+1,grid,dp)+grid[i][j]);
        
    }
public:
    int m,n;
    int minimumTotal(vector<vector<int>>& triangle) {
         m= triangle.size();
         n= triangle[m-1].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
      
        return sol(0,0, triangle,dp);
    }
};
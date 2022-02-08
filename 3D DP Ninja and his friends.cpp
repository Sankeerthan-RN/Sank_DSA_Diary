

//https://www.codingninjas.com/codestudio/problems/ninja-and-his-friends_3125885

int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    vector<vector<vector<int>>>dp(n+2,vector<vector<int>>(m+2,vector<int>(m+2,0)));
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==j)dp[n-1][i][j]=grid[n-1][j];
            else dp[n-1][i][j]=grid[n-1][i]+grid[n-1][j];
            
        }
            
    }
    
    for(int i=n-2;i>=0;i--)
    {
        for(int j1=0;j1<m;j1++)
        {
            for(int j2=0;j2<m;j2++)
            {
                int maxi=-1e8;
                for(int k1=-1;k1<=1;k1++)
                {
                     for(int k2=-1;k2<=1;k2++)
                     {
                         int sum=0;
                         if(j1==j2) sum+=grid[i][j1];
                         else sum+=grid[i][j1]+grid[i][j2];
                         if(j1+k1>=0 && j2+k2>=0 && j1+k1<m &&  j2+k2<m )
                         {
                            sum+=dp[i+1][j1+k1][j2+k2];
                         }
                         else sum=-1e8;
                             
                         
                         maxi=max(sum,maxi);
                         
                         
                     }
                }
                
                dp[i][j1][j2]=maxi;
            }
        }
    }
    return dp[0][0][m-1];
    
}



//https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284
int sol(int idx ,vector<int>&price,vector<int>&dp,int N)
    {
        
        if(idx>N)return INT_MAX;
        if(idx==N)return 0; 
        int ans=0;
         if(dp[idx]!=-1)return dp[idx];
        for(int j=1;j<=N;j++)
        {
            int p=sol(idx+j,price,dp,N)+price[j-1];
          
            ans=max(ans,p);
                   
                   
        }
        return dp[idx]=ans;
    }
    

int cutRod(vector<int> &price, int n)
{
   
    vector<int>dp(n+1,-1);
    return sol(0,price,dp,n);
}

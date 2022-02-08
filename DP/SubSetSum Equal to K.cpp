
//Subset Sum Equal To K
//https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954

int sol(int i,int sum ,vector<int>&arr,vector<vector<int>>&dp)
{
    if(i<0 || sum<0)return 0;
    if(sum==0)return 1;
    if(dp[i][sum]!=-1)return dp[i][sum];
    return dp[i][sum]= (sol(i-1,sum-arr[i],arr,dp)||sol(i-1,sum,arr,dp));
}


bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
    return sol(n-1,k,arr,dp);
}
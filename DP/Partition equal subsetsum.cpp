
//https://leetcode.com/problems/partition-equal-subset-sum/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0,n=nums.size();
       for(auto x:nums)sum+=x;
        
        if(sum&1)return false;
        
        int target=sum/2;
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        
        for(int i=0;i<n;i++)dp[i][0]=1;
        if(nums[0]<=target)
            dp[0][nums[0]] =1;
       
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=target;j++)
            {
                int nopick =dp[i-1][j];
                int pick=0;
                if(nums[i]<=j)pick=dp[i-1][j-nums[i]];
                dp[i][j]=pick or nopick;
                
            }
            
        }
        return dp[n-1][target];
    }
};
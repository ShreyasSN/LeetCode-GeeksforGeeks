class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int dp[2][100000];
        memset(dp, 0, sizeof(dp));
        dp[0][0]=dp[1][0]=nums[0];
        for(int i=1;i<n;i++){
            dp[1][i]=max(dp[1][i-1]+nums[i],nums[i]);
            dp[0][i]=max(dp[0][i-1],dp[1][i]);
        }     
        return dp[0][n-1];
    }
};
class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return false;
        vector<bool> dp = {true, false, n > 1 && nums[0] == nums[1]};
        for(int i=2; i<n; i++){
            bool cur = false;
            if(nums[i] == nums[i-1] && dp[1]) cur = true;
            else if(nums[i] == nums[i-1] && nums[i] == nums[i-2] && dp[0]) cur = true;
            else if(nums[i] - nums[i-1] == 1 && nums[i-1] - nums[i-2] && dp[0]) cur = true;
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = cur;
        }
        return dp[2];
    }
};
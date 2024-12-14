class Solution {

    int solve(vector<int>& nums, int i, vector<int>& memo){
        int n = nums.size();
        if(i >= n) return 0;
        if(memo[i] != -1) return memo[i];
        int take = solve(nums, i+2, memo) + nums[i];
        int nottake = solve(nums, i+1, memo);
        return memo[i] =  max(take, nottake);
    }

public:
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size()+1, -1);
        return nums.empty() ?  : solve(nums, 0, memo);
    }
};
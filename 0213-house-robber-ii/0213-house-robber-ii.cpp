class Solution {
    int dp[101];
    int f(vector<int>& a, int i, bool first){
        if(i >= a.size() - first) return 0;
        if(dp[i] != -1) return dp[i];
        int inc = 0, exc = 0;
        inc = f(a, i+2, first) + a[i];        
        exc = f(a, i+1, first);
        return dp[i] = max(inc, exc);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums.front();
        memset(dp, -1, sizeof(dp));
        int r1 = f(nums, 1, false);
        memset(dp, -1, sizeof(dp)); 
        int r2 = f(nums, 0, true);
        return max(r1,r2);
    }
};
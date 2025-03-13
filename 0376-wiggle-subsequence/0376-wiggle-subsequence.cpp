class Solution {
    int dp[1005][2];
    int f(vector<int>& a, int i, bool pos) {
        if(i == a.size()-1) return 1;
        if(dp[i][pos] != -1) return dp[i][pos];
        int res = INT_MIN;
        if(pos) {
            if(a[i+1] > a[i]) {
                res = max(res, 1+f(a,i+1,!pos));
            } else {
                res = max(res, f(a, i+1, pos));
            }
        } else {
            if(a[i+1] < a[i]) {
                res = max(res, 1+f(a, i+1, !pos));
            } else {
                res = max(res, f(a, i+1, pos));
            }
        }
        return res;
    }
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int res = INT_MIN;
        memset(dp, -1, sizeof(dp));
        res = max(f(nums, 0, false), f(nums, 0, true));
        return res;
    }
};
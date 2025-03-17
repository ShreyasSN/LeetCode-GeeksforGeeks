class Solution {
    int f(vector<int>& a, int i, int rem, auto& dp){
        if(i == a.size()){
            if(rem == 0) return 0;
            else return INT_MIN;
        }
        if(dp[i][rem] != -1) return dp[i][rem];
        int inc = a[i] + f(a, i+1, (rem + a[i]) %  3, dp);
        int exc = f(a, i+1, rem, dp);
        return dp[i][rem] = max(inc, exc);
    }
public:
    int maxSumDivThree(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> dp(n+1, vector<int>(3, -1));
        // return f(nums, 0, 0, dp);
        dp[n][0] = 0;
        dp[n][1] = dp[n][2] = INT_MIN;
        int inc,exc;
        inc = exc = INT_MIN;
        for(int i=n-1; ~i; i--){
            for(int rem=0; rem<3; rem++){
                inc = a[i] + f(a, i+1, (rem + a[i]) %  3, dp);
                exc = f(a, i+1, rem, dp);
                dp[i][rem] = max(inc, exc);
            }
        }
        return dp[0][0];
    }
};
class Solution {
    long long mod = 1e18 + 7;
    int memo(vector<int>& coins, int target, int rem, int i, vector<vector<int>>& dp){
        if(i >= coins.size()) return 0;
        if(rem == target) return 1;
        if(rem > target) return 0;
        int &ans = dp[i][rem];
        if (ans != -1) return ans;
        return ans = (memo(coins, target, rem + coins[i], i, dp)%mod +  memo(coins, target, rem, i + 1, dp)%mod)%mod;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        return memo(coins, amount, 0, 0, dp);
    }
};
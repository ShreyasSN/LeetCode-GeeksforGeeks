class Solution {
    long long int mod = 1e9+7;
    long long int f(vector<long long>& dp, int n){
        if(n == 2) return dp[n] = 3;
        if(n == 1) return dp[n] = 2;
        long long int &ans = dp[n];
        if(ans != -1) return ans;
        return ans = (f(dp, n-1)%mod + f(dp, n-2)%mod) % mod;
    }
public:
    int countHousePlacements(int n) {
        vector<long long int> dp(n+1, -1);
        f(dp, n);
        return ((dp[n]%mod * dp[n]%mod) % mod);
    }
};
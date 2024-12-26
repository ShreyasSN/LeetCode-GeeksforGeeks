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
        vector<long long int> dp(n+1);
        dp[1] = 2;
        if(n > 1) dp[2] = 3;
        for(int i=3; i<=n; i++){
            dp[i] = (dp[i-1]%mod + dp[i -2]%mod ) %mod;
        }
        return ((dp[n]%mod * dp[n]%mod) % mod);
    }
};
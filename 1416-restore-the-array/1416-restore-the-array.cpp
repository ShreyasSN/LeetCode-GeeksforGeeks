class Solution {
    int dp[100001];
    int mod = 1e9 + 7;
    int f(string& s, int k, int i){
        if(i >= s.size())return 1;
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];
        int ways = 0;
        long cur = 0;
        for(int j=i; j<(int)s.size(); j++){
            cur = cur*10 + s[j] - '0';
            if(cur > k) break;
            ways = (ways + f(s, k, j+1)) % mod;
        } 
        return dp[i] = ways;
    } 
public:
    int numberOfArrays(string s, int k) {
        memset(dp, -1, sizeof(dp));
        return f(s, k, 0);
    }
};
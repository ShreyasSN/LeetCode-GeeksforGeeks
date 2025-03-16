class Solution {
    vector<int> dp;
    int f(vector<int>& a, int k, int i){
        int n = a.size();
        if(i == n) return 0;
        if(dp[i] != -1 ) return dp[i];
        int inf = INT_MIN;
        int res = inf, cur = inf, len = 0;
        for(int j=i; j<min(i+k, n); j++) {
            len++;
            cur = max(cur, a[j]);
            int cur_returns = f(a, k, j+1);
            int sum = len * cur + cur_returns;
            res = max(res, sum);
        }
        return dp[i] = res;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        dp.assign(n+1, -1);
        return f(arr, k, 0);
    }
};
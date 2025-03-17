class Solution {
    static const int N = 1e5+1;
    int dp[N][2][2];
    int maxdepth = 0;
    int f(vector<int>& p, int i, int buy, int k, int deep = 0){
        if(i == p.size() || k == 0) return 0;
        maxdepth = max(maxdepth, deep);
        int &res = dp[i][buy][k];
        if(res != -1) return res;
        int sell = INT_MIN, purchase = INT_MIN, exc = 0;
        if(buy) {
            purchase = f(p, i+1, 0, k, deep+1) - p[i];
        } else {
            sell = f(p, i+1, 1, k-1, deep+1) + p[i];
        }
        exc = f(p, i+1, buy, k, deep+1);
        return res = max({sell, purchase, exc});
    }
public:
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        int res = f(prices, 0, 1, 2);
        cout << maxdepth << '\n';
        return res;
    }
};
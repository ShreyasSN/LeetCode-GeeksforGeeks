class Solution {
    vector<pair<int, int>> dir = {{-2, 1}, {2, 1}, {-1, 2}, {1, 2}, {1, -2}, {-1, -2}, {2, -1}, {-2, -1}};
    vector<vector<vector<int>>> dp;

    int f(int n, int i, int j) {
        if (i < 0 || j < 0 || i >= 4 || j >= 3 || (i == 3 && (j == 0 || j == 2))) return 0;
        if (n == 1) return 1;
        if (dp[n][i][j] != -1) return dp[n][i][j];

        int res = 0;
        for (auto& [dx, dy] : dir) {
            int ni = i + dx, nj = j + dy;
            res = (res + f(n - 1, ni, nj)) % 1000000007; 
        }

        return dp[n][i][j] = res;
    }

public:
    int knightDialer(int n) {
        int res = 0;
        dp.assign(n + 1, vector<vector<int>>(4, vector<int>(3, -1)));
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == 3 && (j == 0 || j == 2)) continue; 
                res = (res + f(n, i, j)) % 1000000007;
            }
        }
        return res;
    }
};

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 1)); 
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}}; 
        
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (dp[i][j] != 1) return dp[i][j]; 

            for (auto& dir : directions) {
                int ni = i + dir.first, nj = j + dir.second;
                if (ni >= 0 && nj >= 0 && ni < n && nj < m && matrix[ni][nj] > matrix[i][j]) {
                    dp[i][j] = max(dp[i][j], 1 + dfs(ni, nj)); 
                }
            }

            return dp[i][j];
        };

        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result = max(result, dfs(i, j));
            }
        }

        return result;
    }
};

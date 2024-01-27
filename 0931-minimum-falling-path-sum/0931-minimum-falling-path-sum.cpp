class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(matrix);
        
        for(int i=1; i<dp.size(); i++){
            for(int j=0; j<dp.size(); j++){
                dp[i][j] += min({dp[i-1][j], dp[i-1][max(0, j-1)], dp[i-1][min((int)dp.size()-1, j+1)]});
            }
        }

        return *min_element(dp[dp.size()-1].begin(), dp[dp.size()-1].end());
    }
};
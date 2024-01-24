class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int prev, curr;
        int m = text1.size(), n = text2.size();

        vector<int> dp(n+1, 0);
        for(int i=1; i<=m; i++){
            prev = 0;
            for(int j=1; j<=n; j++){
                curr = dp[j];
                dp[j] = max({dp[j], dp[j-1], prev + (text1[i-1] == text2[j-1])});
                prev = curr;
            }
        }

        return dp[n];
    }
};
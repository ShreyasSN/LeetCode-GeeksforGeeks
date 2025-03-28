class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp (amount + 1);
        dp[0] = 1;
        for(int i=0; i<coins.size(); i++){
            for(int j=coins[i]; j<=amount; j++){
                if (j - coins[i] >= 0)
                    dp[j] += dp[j-coins[i]];
            }
        }
        return dp[amount];
    }
};
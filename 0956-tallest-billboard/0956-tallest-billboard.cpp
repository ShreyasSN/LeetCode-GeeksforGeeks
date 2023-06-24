class Solution {
public:
       int tallestBillboard(std::vector<int>& rods) {
        std::unordered_map<int, int> dp;
        dp[0] = 0;
        
        for (int r : rods) {
            std::unordered_map<int, int> newDp(dp);
            
            for (const auto& entry : dp) {
                int diff = entry.first;
                int taller = entry.second;
                int shorter = taller - diff;
                

                int newTaller = newDp[diff + r];
                newDp[diff + r] = std::max(newTaller, taller + r);
                
                int newDiff = std::abs(shorter + r - taller);
                int newTaller2 = std::max(shorter + r, taller);
                newDp[newDiff] = std::max(newTaller2, newDp[newDiff]);
            }
            
            dp = newDp;
        }
        
        return dp[0];
    }
};
#include <vector>

class Solution {
public:
    int numberOfAlternatingGroups(std::vector<int>& A, int K) {
        int N = A.size();
        A.insert(A.end(), A.begin(), A.end());
        std::vector<int> dp(2 * N, 1);
        
        for (int i = 1; i < 2 * N; ++i) {
            if (A[i] != A[i - 1]) {
                dp[i] = 1 + dp[i - 1];
            }
        }
        
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            if (dp[i] >= K || dp[i + N] >= K) {
                ++ans;
            }
        }
        
        return ans;
    }
};

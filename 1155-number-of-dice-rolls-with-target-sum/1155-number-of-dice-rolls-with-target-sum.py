class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        mod = 10**9+7
        @lru_cache(None)
        def dp(i, rem):
            if i == n: return 1 if rem == 0 else 0
            inc = 0
            for j in range(1, k+1):
                inc = (inc + dp(i+1, rem - j)) % mod
            return inc
        return dp(0, target)
        
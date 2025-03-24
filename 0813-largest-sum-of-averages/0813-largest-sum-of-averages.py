class Solution:
    def largestSumOfAverages(self, nums: List[int], k: int) -> float:
        n = len(nums)
        pref = [0] * (n+1)
        for i in range(1,n+1):
            pref[i] = pref[i-1] + nums[i-1]
        @lru_cache(None)
        def dp(K, start):
            if K==1: return (pref[n]-pref[start])/(n-start)
            cur = 0.0
            for i in range(start, n-K+1):
                cur = max(cur,  1.0*(pref[i+1]-pref[start])/(i+1-start) + dp(K-1, i+1))
            return cur
        return dp(k, 0)
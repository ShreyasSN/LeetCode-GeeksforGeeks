class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        if n <= 1: return 0
        res = 0
        for i in range(1, n):
            res += max(0, prices[i]-prices[i-1])
        return res
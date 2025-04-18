class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        res, cur_max = 0, 0
        n = len(prices)
        for i in range(1, n):
            cur_max += (prices[i] - prices[i-1])
            cur_max = max(0, cur_max)
            res = max(res, cur_max)
        return res

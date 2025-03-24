class Solution:
    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:
        moves = [
            (-2, -1), (-1, -2), (1, -2), (2, -1), (2, 1), (1, 2), (-1, 2), (-2, 1)
        ]
        @lru_cache(None)
        def dp(i, j, p):
            if i < 0 or j < 0 or i >= n or j >= n: return 0
            if p == 0: return 1
            cnt = 0
            dir = [-1, 0, 1, 0, -1]
            for dx, dy in moves:
                cnt = (cnt + dp(dx + i, dy + j, p-1)/8)
            return cnt
        return dp(row, column, k)
            


# probability += (moves==0 ? 1 : 0) / 8
 
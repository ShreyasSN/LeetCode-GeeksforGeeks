class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        @lru_cache(None)
        def dp(i, j):
            if j < 0 or j >= n: return float('inf')
            if i==n-1: return matrix[i][j]
            return min(dp(i+1, j), dp(i+1, j-1), dp(i+1, j+1)) + matrix[i][j]
        return min(dp(0, j) for j in range(n))

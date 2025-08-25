class Solution:
    def maxTurbulenceSize(self, arr: List[int]) -> int:
        n = len(arr)
        if n == 1:
            return 1
        dp = [0 for i in range(n)]
        dp[0] = 1
        dp[1] = 2 if arr[0] != arr[1] else 1
        prev = 0
        for i in range(2, n):
            if (arr[i - 1] < arr[i] and arr[i - 2] > arr[i - 1]) or 
               (arr[i - 1] > arr[i] and arr[i - 2] < arr[i - 1]):
                dp[i] = dp[i - 1] + 1
            else:
                dp[i] = 2 if arr[i] != arr[i - 1] else 1
        return max(dp)
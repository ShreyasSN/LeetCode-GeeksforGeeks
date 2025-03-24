class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        n = len(satisfaction)
        @cache
        def memo(i, time):
            if i == n: return 0
            inc = memo(i+1, time+1) + satisfaction[i] * time
            exc = memo(i+1, time)
            return max(inc, exc)
        satisfaction.sort()
        return memo(0, 1)
class Solution:
    def videoStitching(self, clips: List[List[int]], time: int) -> int:
        n = len(clips)
        clips.sort()
        @lru_cache(None)
        def dp(i, prev):
            if prev >= time: return 0
            if i == n: return float('inf')
            inc = float('inf')
            if prev >= clips[i][0]:
                inc = 1 + dp(i+1, clips[i][1])
            exc = dp(i+1, prev)
            return min(inc, exc)
        return -1 if clips[-1][1] < time else dp(0, 0)

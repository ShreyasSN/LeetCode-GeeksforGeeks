class Solution:
    def get_cnt(self, a, b) -> int: 
        cnt = 0
        for x, y in zip(a, b):
            if x == y: cnt += 1
            else: break
        return cnt

    def longestCommonPrefix(self, words: List[str]) -> List[int]:
        n = len(words)
        res = [0] * (n)
        if n <= 1: return res

        lcp = [self.get_cnt(words[i], words[i+1]) for i in range(n - 1)]

        pref = [0] * (n-1)
        suf = [0] * (n-1)

        pref[0] = lcp[0]
        suf[-1] = lcp[-1]

        for i in range(1, n-1):
            pref[i] = max(pref[i-1], lcp[i])
        for i  in range(n-3, -1, -1):
            suf[i] = max(suf[i+1], lcp[i])

        for i in range(n):
            best = 0
            if i >= 2: best = max(best, pref[i-2])
            if i + 1 <= n - 2: best = max(best, suf[i+1])
            if 0 < i < n-1: best = max(best, self.get_cnt(words[i-1], words[i+1]))
            res[i] = best
        return res
from collections import defaultdict

class Solution(object):
    def canConstruct(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: bool
        """
        if len(s) < k:
            return False
        mp = defaultdict(int)
        for cur in s:
            mp[cur] += 1
        odd_cnt = sum(x & 1 for x in mp.values())
        return odd_cnt <= k

        
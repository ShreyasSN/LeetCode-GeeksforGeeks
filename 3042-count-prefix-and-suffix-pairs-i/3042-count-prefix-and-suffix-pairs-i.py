class Solution(object):
    def countPrefixSuffixPairs(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        n = len(words)
        count = 0
        for i in range(n):
            for j in range(i+1, n):
                if len(words[i]) > len(words[j]):
                    continue
                if words[j].startswith(words[i]) and words[j].endswith(words[i]):
                    count += 1
        return count

        
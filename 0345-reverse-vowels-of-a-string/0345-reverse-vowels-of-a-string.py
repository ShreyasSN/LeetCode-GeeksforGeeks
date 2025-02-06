class Solution:
    def reverseVowels(self, s: str) -> str:
        l, r= 0, len(s)-1
        res = list(s)
        while l < r:
            if res[l].lower() in "aeiou":
                if res[r].lower() in "aeiou":
                    res[l], res[r] = res[r], res[l]
                    l += 1
                    r -= 1
                else:
                    r -= 1
            else:
                l += 1
        return ''.join(res)

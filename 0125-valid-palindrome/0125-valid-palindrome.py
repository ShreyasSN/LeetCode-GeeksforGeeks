class Solution:
    def isPalindrome(self, s: str) -> bool:
        t = ''.join(i.lower() for i in s if i.isalnum())
        l, r = 0, len(t)-1
        while l < r:
            if t[l] != t[r]: return False
            l += 1
            r -= 1
        return True

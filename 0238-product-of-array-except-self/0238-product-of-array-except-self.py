class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        prefix = [1] * n
        sufix = [1] * n

        prefix[0] = 1
        for i in range(1, n):
            prefix[i] =prefix[i-1] * nums[i-1]

        sufix[n-1] = 1
        for i in range(n-2, -1, -1):
            sufix[i] = sufix[i+1] * nums[i+1]
        
        res = [1] * n
        for i in range(n):
            res[i] = prefix[i] * sufix[i]
            
        return res

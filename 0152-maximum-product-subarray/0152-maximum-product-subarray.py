class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        n=len(nums)
        if n==0:
            raise ValueError
        dp1 = [0]*n
        dp2 = [0]*n
        dp1[0] = nums[0]
        dp2[0] = nums[0]
        for i in range(1, len(nums)):
            dp1[i]=max(dp1[i-1]*nums[i], dp2[i-1]*nums[i], nums[i])
            dp2[i]=min(dp1[i-1]*nums[i], dp2[i-1]*nums[i], nums[i])
        return max(dp1)
        
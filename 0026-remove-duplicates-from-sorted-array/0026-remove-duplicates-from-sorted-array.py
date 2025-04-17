class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        # [0,0,1,1,1,2,2,3,3,4]
        n = len(nums)
        k = 1
        for i in range(n):
            if i == 0 or nums[i-1] == nums[i]:
                continue
            else:
                nums[k] = nums[i]
                k += 1
        return k
                

"""
    restate the problem
    claryfying questions
    eg walkthrough
    brute force idea -> inefficiency -> Discuss TC & SC
    Optimial Solution
    Reason for choosing
    Pseudocode
    Outline the implementation
    Testcases check -> Edgecases check
    discuss TC & SC
    feedback
"""
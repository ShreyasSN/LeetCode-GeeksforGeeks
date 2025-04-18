class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        freq = Counter(nums)
        mx, cnt = 0, 0
        for cur_item, item_cnts in freq.items():
            if item_cnts > cnt:
                cnt = item_cnts
                mx = cur_item
        return mx
            
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left =0, zeroflip  =1, right;
        
        for(right=0; right<nums.size(); right++)
        {
            if(nums[right] == 0) zeroflip--;
            if(zeroflip<0 && nums[left++] == 0) zeroflip++;
        }
        
        return right - left - 1;
    }
};
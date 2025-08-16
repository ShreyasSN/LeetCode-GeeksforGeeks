class Solution {
public:
    bool search(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int m = l + (r - l) / 2;
            if(nums[m] == k) { return true; }
            else if(nums[m] == nums[l] && nums[m] == nums[r]) { r--, l++; }
            else if(nums[m] >= nums[l]) {
                if((nums[l] <= k) && (nums[m]) > k) { r = m - 1; }
                else { l = m + 1; }
            } else {
                if((nums[m] < k) && (nums[r] >= k)) { l = m + 1; }
                else { r = m - 1; }
            }
        }
        return false;
    }
};
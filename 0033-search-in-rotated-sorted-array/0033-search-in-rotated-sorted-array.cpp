class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l < r) {
            int m =(l + r) / 2;
            if(nums[m] < nums[r]) r = m;
            else l = m + 1;
        }
        int rot = l;
        l = 0, r = n-1;
        while(l <= r) {
            int m = l + (r - l) / 2;
            int rm = (m + rot) % n;
            if(nums[rm] == target) return rm;
            else if(nums[rm] > target) r = m - 1;
            else l = m + 1;
        }
        return -1;
    }
};
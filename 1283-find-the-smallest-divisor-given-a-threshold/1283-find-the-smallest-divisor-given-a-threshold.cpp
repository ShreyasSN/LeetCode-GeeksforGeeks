class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int l = 1, r = *max_element(nums.begin(), nums.end());
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int c = 0;
            for (auto x : nums)
                c += (((x - 1) / mid) + 1);
            if (c <= threshold) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
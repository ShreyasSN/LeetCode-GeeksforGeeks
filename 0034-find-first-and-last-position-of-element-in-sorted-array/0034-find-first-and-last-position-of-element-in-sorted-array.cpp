class Solution {
    template <typename T, typename U>
    T bsearch(T l, T r, U condition, bool Lbound = true, bool firstTSeq = false) {
        while (l < r) {
            T mid = l + (r - l + firstTSeq) / 2;
            if (condition(mid)) firstTSeq ? l = mid : r = mid;
            else firstTSeq ? r = mid - 1 : l = mid + 1;
        }
        return (Lbound ? l : l - 1);
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1, -1};
        
        int l = 0, r = nums.size();
        int x = bsearch(l, r, [&](int m) {
            return nums[m] >= target;
        });
        int y = bsearch(l, r, [&](int m) {
            return nums[m] > target;
        }, false);

        x = (x >= 0 && nums[x] == target) ? x : -1;
        y = (y < nums.size() && nums[y] == target) ? y : -1;

        return {x, y};
    }
};
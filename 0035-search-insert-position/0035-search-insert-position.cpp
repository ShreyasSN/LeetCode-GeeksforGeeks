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
    int searchInsert(vector<int>& nums, int target) {
        return bsearch(0, (int)nums.size(), [&](int m) {
            return nums[m] >= target;
        });
    }
};
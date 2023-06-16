class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int res = 0;
        vector<int> copy(nums);
        vector<int> bit(copy.size() + 1);

        sort(copy.begin(), copy.end());

        for (int ele : nums) {
            res += search(bit, index(copy, 2L * ele + 1));
            insert(bit, index(copy, ele));
        }

        return res;
    }

private:
    int index(vector<int>& arr, long val) {
        int l = 0, r = arr.size() - 1, m = 0;

        while (l <= r) {
            m = l + ((r - l) >> 1);

            if (arr[m] >= val) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return l + 1;
    }

    int search(vector<int>& bit, int i) {
        int sum = 0;

        while (i < bit.size()) {
            sum += bit[i];
            i += i & -i;
        }

        return sum;
    }

    void insert(vector<int>& bit, int i) {
        while (i > 0) {
            bit[i] += 1;
            i -= i & -i;
        }
    }
};
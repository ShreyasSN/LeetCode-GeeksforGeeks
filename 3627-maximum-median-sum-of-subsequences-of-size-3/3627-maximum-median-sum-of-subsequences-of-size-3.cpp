class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        sort(nums.begin(), nums.end());
        int i = 0, j = n - 1;
        while (i + 1 < j) {
            int a = nums[i++];
            int b = nums[j--];
            int c = nums[j--];
            if (a > b)
                swap(a, b);
            if (b > c)
                swap(b, c);
            res += b;
        }
        return res;
    }
};
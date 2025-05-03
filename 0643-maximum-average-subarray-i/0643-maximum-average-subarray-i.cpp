class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0;
        double res = -DBL_MAX, sum = 0.0;
        for(; r<n; r++) {
            if(r-l+1 < k) {
                sum += nums[r];
            } else {
                sum += nums[r];
                res = max(res, sum/k);
                sum -= nums[l++];
            }
        }
        return res;
    }
};
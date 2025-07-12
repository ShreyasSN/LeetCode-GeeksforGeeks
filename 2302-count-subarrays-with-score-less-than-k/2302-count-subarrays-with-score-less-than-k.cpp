class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        long long totalCount = 0;

        for (int start = 0; start < n; ++start) {
            int l = start, r = n - 1;
            int validEnd = -1;

            while (l <= r) {
                int m = l + (r - l) / 2;
                long long sum = prefix[m + 1] - prefix[start];
                long long score = sum * (m - start + 1);
                
                if (score < k) {
                    validEnd = m;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }

            if (validEnd != -1) {
                totalCount += (validEnd - start + 1);
            }
        }

        return totalCount;
    }
};

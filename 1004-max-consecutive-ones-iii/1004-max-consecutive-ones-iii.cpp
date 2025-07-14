class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int freq[2]{};
        int l = 0, r = 0;
        int res = 0;

        for(; r<n; r++) {
            freq[nums[r]]++;
            while(freq[0] > k && l <= r) {
                freq[nums[l++]]--;
            }
            
            res = max(res, r - l + 1);
        }

        return res;
    }
};
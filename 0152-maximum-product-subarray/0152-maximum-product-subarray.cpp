class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0], n = nums.size(), l=0, r=0;
        for(int i=0; i<n; i++)
        {
            l = (l ? l : 1)*nums[i];
            r = (r ? r : 1)*nums[n-1-i];
            result = max(result, max(l, r));
        }
        return result;
    }
};
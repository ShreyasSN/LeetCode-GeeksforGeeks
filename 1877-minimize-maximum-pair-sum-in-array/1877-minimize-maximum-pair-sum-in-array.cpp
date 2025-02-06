class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i=0, j=(int)nums.size()-1; i<j;){
            res = max(res, nums[i] + nums[j]);
            i++, j--;
        }
        return res;
    }
};
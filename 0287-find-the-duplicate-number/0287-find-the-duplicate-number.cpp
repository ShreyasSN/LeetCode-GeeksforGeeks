class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n+1);
        for(int i=0; i<n;i++)
        {
            ans[nums[i]]++;
            if(ans[nums[i]] > 1) return nums[i];
        }
        return n;
    }
};
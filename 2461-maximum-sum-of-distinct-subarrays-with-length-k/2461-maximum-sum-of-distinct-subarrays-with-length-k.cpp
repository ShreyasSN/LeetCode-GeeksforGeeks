class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int ,int> mp;
        long long cur=0, res=0;
        int n = nums.size();
        int l=0, r=0;
        while(r<n){
            if(r-l+1 < k){
                mp[nums[r]]++;
                cur += nums[r++];
            } else {
                mp[nums[r]]++;
                cur += nums[r];
                if(mp.size()==k) res = max(res, cur);
                cur -= nums[l];
                if(--mp[nums[l]] == 0) mp.erase(nums[l]);
                l++, r++;
            }
        }
        return res;
    }
};
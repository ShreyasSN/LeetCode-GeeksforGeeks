class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count = (nums.size())/3;
        unordered_map<int, int> mp;
        set<int>res;
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]] > count) res.insert(nums[i]);
        }
        vector<int>ans(res.begin(), res.end());
        return ans;
    }
};
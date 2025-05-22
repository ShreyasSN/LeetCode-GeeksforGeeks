class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int mx = 0;
        for(int i:nums) mx = max(mx, ++mp[i]);
        return n - mx;
    }
};
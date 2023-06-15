class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int res = 0;
        for(auto x : nums)
        {
            if(mp[x]) continue;
            res = max(res, mp[x] = mp[x - mp[x-1]] = mp[x + mp[x+1]] = mp[x+ mp[x+1]] + mp[x - mp[x-1]] + 1 );
        }
        return res;
    }
};
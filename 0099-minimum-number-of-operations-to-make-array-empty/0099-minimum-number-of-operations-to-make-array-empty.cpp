class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto& x : nums){
            mp[x]++;
        }
        
        int res = 0;

        for(const auto& [a, b] : mp){
            if(b == 1) return -1;
            res += b/3 + (b % 3 > 0);
        }
        return res;
    }
};
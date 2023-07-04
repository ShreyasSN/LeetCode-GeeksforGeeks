class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        long long diff= accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        
        diff &= -diff;
        
        int a=0, b=0;
        
        for(int x : nums)
        {
            if(x & diff) a ^= x;
            else b ^= x;
        }
        
        return {a, b};
    }
};
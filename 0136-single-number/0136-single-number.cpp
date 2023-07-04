class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // k = 2, p = 1
        
        // 2^m = k, m = 1
        
        int x1 = 0;
        
        for(int i: nums)
        {
            x1 ^= i;
        }
        
        return x1;
    }
};
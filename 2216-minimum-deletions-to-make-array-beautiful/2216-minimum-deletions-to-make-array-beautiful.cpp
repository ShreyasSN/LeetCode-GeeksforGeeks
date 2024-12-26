class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int reversed = 0, res = 0;
        int rev = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == nums[i + 1] && rev == i%2) {
                rev ^= 1;
                res++;
            }
        }
        return (nums.size() - res) % 2 + res;
    }
};
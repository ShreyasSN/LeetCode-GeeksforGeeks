class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
        auto get = [&] (int &a, int &b) {
            int i = 0;
            for (; (b >> i); i++) {}
            return ((a << i) | b);
        };
        auto comp = [&] (int &a, int &b) {
            return get(a, b) > get(b, a);
        };
        sort(nums.begin(), nums.end(), comp);
        int num = 0;
        
        for (auto &it : nums) {
            num = get(num, it);
        }
        return num;
    }
};
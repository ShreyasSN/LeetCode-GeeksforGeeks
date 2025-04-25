class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c <= 1) return true;
        long long l = 0, r = sqrt(c) + 1;
        while(l < r) {
            long long cur = l*l + r*r;
            if(cur == static_cast<long long>(c)) return true;
            else if(cur < c) l++;
            else r--;
        }
        return false;
    }
};
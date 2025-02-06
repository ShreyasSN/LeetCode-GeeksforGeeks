class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long long i=0, j=sqrt(c); i<=j;){
            if((i*i + j*j) == c) return true;
            ((i*i + j*j) < c) ? i++ : j--;
        }
        return false;
    }
};
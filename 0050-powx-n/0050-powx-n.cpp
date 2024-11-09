class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0) x = 1/x;
        long long num = llabs(n);
        double p = 1;
        while(num){
            if(num & 1) p *= x;
            x *= x;
            num >>= 1;
        }
        return p;
    }
};
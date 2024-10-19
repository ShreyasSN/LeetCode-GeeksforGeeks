class Solution {
public:
    int divide(int d, int r) {
        // return dividend/divisor; // O(1)
        if(d == r) return 1;
        bool ip = (d > 0 == r > 0);
        unsigned int a = abs(d);
        unsigned int b = abs(r);
        unsigned int ans=0;
        while(a >= b){
            short q = 0;
            while(a > (b << (q+1))) q++;
            ans += (1 << q);
            a = a - (b << q);
        }
        if(ans == (1 << 31) and ip) return INT_MAX;

        return ip ? ans : - ans;
    }
};

// dividend = (quotient) * divisor + remainder

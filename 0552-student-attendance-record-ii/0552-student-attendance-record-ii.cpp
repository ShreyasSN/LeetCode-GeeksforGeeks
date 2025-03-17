class Solution {
    int dp[100001][2][4];
    const int mod = 1e9 + 7;
    int f(int n, int a, int l){
        if(n == 0) return 1;

        int &res = dp[n][a][l];
        if(res != -1) return res;

        int absent, late, present;
        absent = late = present = 0;

        if(a==0) absent = f(n-1, a+1, 0);
        if(l < 2) late = f(n-1, a, l+1);
        present = f(n-1, a, 0);

        return res = ((absent + present) % mod + late) % mod;
    }
public:
    int checkRecord(int n) {
        memset(dp, -1, sizeof(dp));
        return f(n, 0, 0);
    }
};


// attendance {
//     absent  |   late   
//     1           0       => #absents < 2
//     0           1       => #consecutiveLate < 3
//     0           0       => present on time
// }
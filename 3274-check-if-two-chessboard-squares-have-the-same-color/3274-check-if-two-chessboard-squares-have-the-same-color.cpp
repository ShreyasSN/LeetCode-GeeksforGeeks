class Solution {
public:
    bool checkTwoChessboards(string c1, string c2) {
        int a = (c1[0] & 31)%2 ^ (c1[1] - '0')%2;
        int b = (c2[0] & 31)%2 ^ (c2[1] - '0')%2;
        return a == b;
    }
};
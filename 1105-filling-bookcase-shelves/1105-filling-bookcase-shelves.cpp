class Solution {
    int f(auto& b, int s, auto& dp, int rem, int i, int h){
        if(i == b.size()) return 0;
        int &res = dp[i][rem];
        if(res != -1) return res;
        int inc1 = h + f(b, s, dp, s - b[i][0], i+1, b[i][1]);
        int inc2 = INT_MAX;
        
        if(rem >= b[i][0]) {
            inc2 = f(b, s, dp, rem - b[i][0], i+1, max(h, b[i][1]));
        }
        res = min(inc1, inc2);
        return res;
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<vector<int>> dp(n+1, vector<int>(shelfWidth+1, -1));
        return f(books, shelfWidth, dp, shelfWidth, 0, 0);
    }
};


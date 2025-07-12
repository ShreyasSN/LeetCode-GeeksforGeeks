class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        int score = 0, res = 0;
        sort(tokens.begin(), tokens.end());
        for(int l=0, r=n-1; l<=r; ) {
            cout << l << ' ' << r << ' ' << score << ' ' << power << '\n';
            if(power >= tokens[l]) {
                score += 1;
                power -= tokens[l];
                l += 1;
            }
            else {
                score -= 1;
                power += tokens[r];
                r -= 1;
            }
            res = max(score, res);
        }
        return res;
    }
};
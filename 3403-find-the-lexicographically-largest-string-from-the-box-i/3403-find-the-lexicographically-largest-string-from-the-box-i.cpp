class Solution {
public:
    string answerString(string w, int k) {
        int n = w.size();
        if(k == 1) return w;
        string res = "";
        int p = n - (k - 1);
        for (int i = 0; i < n; i++) {
            res = max(res, w.substr(i, p));
        }
        return res;
    }
};

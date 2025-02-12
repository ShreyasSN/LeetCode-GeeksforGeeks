class Solution {
public:
    string reverseWords(string s) {
        string res, w;
        istringstream ss(s);
        while (ss >> w) {
            reverse(w.begin(), w.end());
            if(!res.empty()) res = res + " ";
            res += w;
        }
        return res;
    }
};
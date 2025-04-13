class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        int m = n/2;
        string res = s.substr(0, m);
        sort(res.begin(), res.end());
        string rev = res;
        reverse(rev.begin(), rev.end());
        if(n&1) res += s[m];
        return  res + rev;
    }
};
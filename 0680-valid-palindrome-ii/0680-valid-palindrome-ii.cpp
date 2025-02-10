class Solution {
public:
    bool validPalindrome(string s) {
        int l=0, r=s.size()-1;
        while(l<r){
            if(s[l] != s[r]){
                int i1 = l, j1 = r-1, i2 = l+1, j2 = r;
                while(i1 < j1 && s[i1] == s[j1]) i1++, j1--;
                while(i2 < j2 && s[i2] == s[j2]) i2++, j2--;
                return i1 >= j1 || i2 >= j2;
            }
            l++, r--;
        }
        return true;
    }
};
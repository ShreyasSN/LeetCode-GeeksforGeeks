class Solution {
    bool check(char a){
        return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
    }
public:
    string reverseVowels(string s) {
        int n = s.size();
        int l=0, r=n-1;
        while(l<r){
            while(l<r && !check(tolower(s[l]))) ++l;
            while(l<r && !check(tolower(s[r]))) --r;
            swap(s[l++], s[r--]);
        }
        return s;
    }
};
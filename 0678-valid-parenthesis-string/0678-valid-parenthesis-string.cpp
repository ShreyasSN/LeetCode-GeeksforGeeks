class Solution {
public:
    bool checkValidString(string s) {
        int open = 0, close = 0;

        for(auto x : s){
            if(x == '(') {
                open++;
                close++;
            }
            else if(x == ')') {
                open--;
                close--;
            }
            else if(x == '*'){
                open++;
                close--;
            }
            if(open < 0) return false;
            close = max(close, 0);  // COOL MAHN
        }
        return close == 0;
    }
};
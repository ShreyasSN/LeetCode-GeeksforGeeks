class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, curr = 0, ans = 0;
        for(string s : bank){
            curr = 0;
            for(char c : s){
                if(c == '1') curr++;
            }
            if(curr != 0) {
                ans += (prev * curr);
                prev = curr;
            }
        }
        return ans;
    }
};
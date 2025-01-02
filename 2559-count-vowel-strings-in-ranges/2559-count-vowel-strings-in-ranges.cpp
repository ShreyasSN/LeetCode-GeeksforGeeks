class Solution {
    bool valid(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int check(string s){
        return s.back() == s.front() && valid(s.back());
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> pref(n+1,0), res;
        pref[0] = 0;
        for(int i=1; i<=n; i++){
            pref[i] = pref[i-1] + check(words[i-1]);
        }
        for(int i=0; i<pref.size(); i++) cout << pref[i] << " ";
        for(int i=0; i<(int)queries.size(); i++){
            int l = queries[i][0], r = queries[i][1];
            res.push_back(pref[r+1] - pref[l]);
        }
        return res;
    }
};
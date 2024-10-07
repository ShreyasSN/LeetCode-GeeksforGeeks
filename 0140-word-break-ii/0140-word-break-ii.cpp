class Solution {
    void solve(string s, vector<string>& w, vector<string> temp, unordered_set<string>& st, vector<string>& res){
        if(s.length() == 0){
            string str = "";
            for(auto it: temp) str += it + " ";
            str.pop_back();
            res.push_back(str);
            return;
        }

        for(int i=0; i<s.length(); i++){
            if(st.count(s.substr(0,i+1))){
                temp.push_back(s.substr(0,i+1));
                solve(s.substr(i+1), w, temp, st, res);
                temp.pop_back();
            }
        }
        return;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<string> res;
        solve(s, wordDict, {}, st, res);
        return res;
    }
};
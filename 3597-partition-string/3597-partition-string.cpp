class Solution {
public:
    vector<string> partitionString(string s) {
        vector<string> res;
        map<string, bool> seen;
        string t;
        for(int i=0; i<(int)s.size(); i++) {
            t += s[i];
            if(!seen[t]) {
                res.push_back(t);
                seen[t] = true;
                t = "";
            }
        }
        return res;
    }
};
class Solution {
public:
    int maxCandies(vector<int>& s, vector<int>& c, vector<vector<int>>& k, vector<vector<int>>& b, vector<int>& start) {
        int n = s.size();
        vector<bool> reach(n, false);
        queue<int> q;
        for(int& i:start) {
            if(s[i]) q.push(i);
            else reach[i] = true;
        }
        int res = 0;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            res += c[u];
            for(int& v:k[u]) {
                if(s[v]==0 && reach[v]) q.push(v);
                s[v] = 1;
            }
            for(int& v:b[u]) {
                if(s[v]==1) q.push(v);
                reach[v] = true;
            }
        }
        return res;
    }
};
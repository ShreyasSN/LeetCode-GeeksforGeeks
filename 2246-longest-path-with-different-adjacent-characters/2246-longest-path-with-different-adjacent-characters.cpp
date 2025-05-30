class Solution {
    vector<vector<int>> g;
    int res;

    int dfs(string& s, int u) {
        if(g[u].empty()) return 1;
        int mx1 = 0 , mx2 = 0;

        for(auto& v:g[u]) {
            int len = dfs(s, v);
            res = max(res, len);
            if(s[u] == s[v]) continue;
            if(len > mx1) {
                mx2 = mx1;
                mx1 = len;
            } else {
                mx2 = max(mx2, len);
            }
        }
        res = max(res, 1 + mx1 + mx2);
        return mx1 + 1;
    }
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        g.resize(n);
        for(int i=1; i<n; i++) {
            g[parent[i]].push_back(i);
        }
        res = 1;
        dfs(s, 0);
        return res;
    }
};
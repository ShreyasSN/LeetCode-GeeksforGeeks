class Solution {
    vector<vector<int>> g;
    int dfs(int u, vector<int>& res, vector<int>& q) {
        if(res[u] != -1) return res[u];
        res[u] = u;
        for(int& v:g[u]) {
            int cur = dfs(v, res, q);
            if(q[cur] < q[u]) res[u] = cur;
        }
        return res[u];
    }
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int m = richer.size();
        int n = quiet.size();
        g.resize(n);
        for(auto e:richer) {
            g[e[1]].push_back(e[0]);
        }
        vector<int> res(n, -1);
        for(int i=0; i<n; ++i) {
            dfs(i, res, quiet);
        }
        return res;
    }
};
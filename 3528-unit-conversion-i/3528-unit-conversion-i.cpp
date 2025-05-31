class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& con) {
        int n = con.size();
        int mod = (int)1e9 + 7;
        vector<vector<pair<int, int>>> g(n + 1);

        for (auto& e : con) {
            g[e[0]].push_back({e[1], e[2]});
        }

        vector<int> res(n + 1, -1);
        vector<bool> vis(n + 1, false);
        res[0] = 1;

        function<void(int)> dfs = [&](int u) {
            vis[u] = true;
            for (auto& [v, c] : g[u]) {
                if (!vis[v]) {
                    res[v] = (1LL * res[u] * c) % mod;
                    dfs(v);
                }
            }
        };

        dfs(0);
        return res;
    }
};

class Solution {
    vector<vector<pair<int,int>>> g;
    vector<int> vis;

    int dfs(int u, int& res) {
        vis[u] = true;
        for(auto [v, dist] : g[u]) {
            res = min(res, dist);
            if(!vis[v]) {
                res = min(res, dfs(v, res));
            }
        }
        return res;
    }
public:
    int minScore(int n, vector<vector<int>>& edges) {
        g.resize(n + 1);
        vis.assign(n + 1, false);
        for(const auto& e:edges) {
            g[e[0]].push_back({e[1], e[2]});
            g[e[1]].push_back({e[0], e[2]});
        }

        int res = INT_MAX;
        dfs(1, res);
        return res;
    }
};
class Solution {
    int N, mod = 1e9+7;
    vector<int> vis, dist, dp;
    vector<vector<pair<int, int>>> adj;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        N = n;
        adj.resize(n + 1);
        vis.resize(n+1);
        dist.resize(n + 1, INT_MAX);
        dp.resize(n + 1, -1);

        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        dist[N] = 0;
        pq.push({0, N});
        
        while (!pq.empty()) {
            auto [cd, cn] = pq.top(); pq.pop();
            if (cd > dist[cn]) continue;
            for (auto& i : adj[cn]) {
                auto [v, d] = i;
                if(!vis[v]){
                if (dist[v] > cd + d) {
                    dist[v] = cd + d;
                    pq.push({dist[v], v});
                }}
            }
        }

        return dfs(1);
    }

    int dfs(int u) {
        if (dp[u] != -1) return dp[u];
        if (u == N) return 1;

        int ans = 0;
        for (auto& p : adj[u]) {
            int v = p.first;
            if (dist[v] < dist[u]) {
                ans = (ans + dfs(v)) % mod;
            }
        }
        return dp[u] = ans;
    }
};

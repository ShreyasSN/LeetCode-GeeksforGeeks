class Solution {
    vector<vector<int>> g;
    vector<bool> vis;
    using ll = long long;

    void dfs(int u, ll& cnt) {
        if(vis[u]) return;
        vis[u] = true;
        cnt+=1;
        for(int& v:g[u]) {dfs(v, cnt);}
    }

public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        g.resize(n);
        vis.assign(n, false);

        for(auto& e:edges) {
            g[e[1]].push_back(e[0]);
            g[e[0]].push_back(e[1]);
        }    

        ll res = ((ll)n * (n-1)) / 2;
        for(int i=0; i<n; i++) {
            ll cnt = 0;
            dfs(i, cnt);
            res -= (cnt * (cnt - 1)) / 2;
        }

        return res;
    }
};
class Solution {
    vector<bool> vis;
    vector<vector<int>> g;

    bool dfs(int u, int d) {
        if(u == d) return true;
        if(vis[u]) return false;
        vis[u] = true;
        for(int v:g[u]) if(dfs(v, d)) return true;
        return false;
    } 

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vis.assign(n, false);
        g.resize(n);
        for(auto e:edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        return dfs(source, destination);
    }
};
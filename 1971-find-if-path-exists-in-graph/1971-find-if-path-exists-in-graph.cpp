class Solution {
    vector<vector<int>> g;
    vector<bool> vis;
    void dfs(int u){
        if(vis[u]) return;
        vis[u] = true;
        for(auto& v:g[u]) dfs(v);
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        g.resize(n);
        vis.assign(n, false);
        for(auto& e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        dfs(source);
        return vis[destination];
    }
};
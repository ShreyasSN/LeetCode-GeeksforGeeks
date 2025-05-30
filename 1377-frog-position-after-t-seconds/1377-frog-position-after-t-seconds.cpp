class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        int m = edges.size();
        vector<vector<int>> g(n);
        for(auto& e:edges) {
            g[e[0]-1].push_back(e[1]-1);
            g[e[1]-1].push_back(e[0]-1);
        }

        vector<bool> vis(n, false);
        vector<double> prb(n);
        queue<int> q;

        q.push(0);
        vis[0] = true;
        prb[0] = 1.0;

        while(!q.empty() && t--) {
            int sz = q.size();
            for(int i=sz; i>0; i--) {
                int u = q.front(); q.pop();
                int cnt = 0;
                for(const int& v:g[u]) if(!vis[v]) {cnt++;}
                for(const int& v:g[u]) if(!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                    prb[v] = prb[u] / cnt;
                }
                if(cnt > 0) prb[u] = 0;
            }
        }

        return prb[target-1];
    }
};
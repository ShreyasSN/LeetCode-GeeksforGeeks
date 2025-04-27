class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& con) {
        int n = con.size();
        int mod = (int)1e9+7;
        vector<vector<pair<int,int>>> g(n+1);
        for(auto e:con) {
            g[e[0]].push_back({e[1], e[2]});
        }
        queue<int> q;
        q.push(0);
        vector<int> res(n+1, -1);
        res[0] = 1;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(auto [v, f]:g[u]) {
                if(res[v] == -1) {
                    res[v] = (1ll * res[u] * f) % mod;
                    q.push(v);  
                }
            }
        }
        return res;
    }
};
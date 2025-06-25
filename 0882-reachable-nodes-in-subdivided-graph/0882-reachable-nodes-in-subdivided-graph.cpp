class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int,int>>> g(n);
        for(auto& e:edges) {
            g[e[0]].push_back({e[1], e[2]});
            g[e[1]].push_back({e[0], e[2]});
        }
        
        using T = pair<int,int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        vector<int> dist(n, (int)1e8);
        
        pq.push({0, 0});
        dist[0] = 0;

        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue; 

            for(auto& [v, w]: g[u]) if(dist[v] > dist[u] + w + 1) {
                dist[v] = dist[u] + w + 1;
                pq.push({dist[v], v});
            }
        }

        int res = 0;
        for(int i=0; i<n; i++) if(dist[i] <= maxMoves) {
            res++;
        }

        for(auto& e:edges) {
            int x = max(0, (maxMoves - dist[e[0]]));
            int y = max(0, (maxMoves - dist[e[1]]));

            res += min(e[2], x + y);
        }

        return res;
    }
};
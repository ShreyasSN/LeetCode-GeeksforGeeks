class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> g(n);
        vector<int> deg(n, 0), maxtime(n, 0);
        queue<int> q;

        for(auto e:relations) {
            g[--e[0]].push_back(--e[1]);
            deg[e[1]]++;
        }
        
        for(int i=0; i<n; i++) if(deg[i] == 0) {
            q.push(i);
            maxtime[i] = time[i];
        }
        
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int v : g[u]) {
                maxtime[v] = max(maxtime[v], time[v] + maxtime[u]);
                if(--deg[v] == 0) {
                    q.push(v);
                }
            }
        }

        return *max_element(maxtime.begin(), maxtime.end());    
    }
};
class Solution {
    void cyclen(vector<int>& e, vector<bool>& vis, vector<int>& res, int u) {
        int len = 0;
        for(int v = u; !vis[v]; v = e[v]) {
            vis[v] = true;
            len++;
        }

        res[u] = len;
        for(int v = e[u]; v != u; v = e[v]) {
            res[v] = len;
        }
    }
public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        vector<int> deg(n,0), res(n);
        vector<bool> vis(n);
        queue<int> q;
        stack<int> s;
        for(const int& e:edges) deg[e]++;
        for(int i=0; i<n; i++) if(!deg[i]) {
            q.push(i);
        }

        while(!q.empty()) {
            int x = q.front(); q.pop();
            s.push(x);
            vis[x] = true;
            if(--deg[edges[x]] == 0) {
                q.push(edges[x]);
            }
        }

        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                cyclen(edges, vis, res, i);
            }
        }

        while(!s.empty()) {
            int x = s.top(); s.pop();
            res[x] = res[edges[x]] + 1;
        }

        return res;
    }
};
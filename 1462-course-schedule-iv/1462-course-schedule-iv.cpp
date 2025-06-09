class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<int>> g(n);
        vector<int> deg(n,0);
        for(auto e:edges){
            g[e[0]].push_back(e[1]);
            deg[e[1]]++;
        }
        queue<int> q;
        for(int i=0; i<n; i++) {
            if(deg[i] == 0) q.push(i);
        }
        unordered_map<int, unordered_set<int>> pre;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int v:g[u]) {
                pre[v].insert(u);
                for(auto k:pre[u]) pre[v].insert(k);
                if(--deg[v] == 0) q.push(v);
            }
        }
        vector<bool> res;
        for(auto qi:queries) {
            res.push_back(pre[qi[1]].contains(qi[0]));
        }
        return res;
    }
};
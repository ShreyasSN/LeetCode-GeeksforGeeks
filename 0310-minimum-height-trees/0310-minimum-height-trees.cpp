class Solution {
    vector<vector<int>> g; vector<bool> vis;
    int dfs(int node){
        vis[node] = true;
        int H=1;
        for(int &i: g[node]){
            if(!vis[i]){
                H = max(H, 1 + dfs(i));
            }
        }
        vis[node] = false;
        return H;
    }
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        g.resize(n); vis.resize(n,false);

        for(auto e: edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        vector<int> ans;

        for(int i=0, minH=n; i<n; i++){
            int H = dfs(i);
            if(H < minH){
                minH = H;
                ans.clear();
            }
            if(H == minH) ans.push_back(i);
        }

        return ans;
    }
};
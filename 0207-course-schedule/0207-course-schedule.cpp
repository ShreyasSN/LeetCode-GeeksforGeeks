class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p){
        vector<vector<int>> g(n);
        vector<int> degree(n,0);
        queue<int> bfs;
        for(auto e: p){
            g[e[0]].push_back(e[1]);
            degree[e[1]]++;
        }
        vector<int> top_sort;
        for(int i=0; i<n; i++){
            if(degree[i] == 0) bfs.push(i);
        }

        while(!bfs.empty()){
            int curr = bfs.front(); bfs.pop();
            top_sort.push_back(curr);
            for(int &i : g[curr]){
                if(--degree[i] == 0) bfs.push(i);   
            }
        }
        return top_sort.size() == n;
    }
};
        
    
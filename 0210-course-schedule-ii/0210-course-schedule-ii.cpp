class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<vector<int>> g(n);
        vector<int> degree(n,0), top_sort;
        queue<int> q;

        for(auto e: p){
            g[e[1]].push_back(e[0]);
            degree[e[0]]++;
        }

        for(int i=0; i<n; i++){
            if(degree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int curr=q.front(); q.pop();
            top_sort.push_back(curr);
            for(int &i: g[curr]){
                if(--degree[i]==0) q.push(i);
            }
        }

        if(top_sort.size()==n) return top_sort;
        return {};
        
    }
};
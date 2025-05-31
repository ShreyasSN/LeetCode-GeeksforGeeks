class Solution {
    long long res = 0;
    vector<vector<int>> g;
    
    int dfs(int u, int prev, int seats, int people = 1) {
        for(int& v:g[u]) if(v != prev) {
            people += dfs(v, u, seats);
        }
        if(u != 0 ) res += (people + seats - 1) / seats;
        return people;
    }
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        g.resize(n);
        int indexing = 0;
        for(const auto& e:roads) {
          g[e[0]-indexing].push_back(e[1]-indexing);
          g[e[1]-indexing].push_back(e[0]-indexing);
        }
        dfs(0, 0, seats);
        return res;
        
    }
};
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> d(n, 0), res;
        for(auto e: edges) d[e[1]]++;
        for(int i=0; i<n; i++) if(d[i] == 0) res.push_back(i);
        return res;
    }
};
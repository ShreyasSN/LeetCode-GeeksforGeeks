class Solution {
    struct pair_hash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };

public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<vector<pair<int, int>>> g(n + 1);
        unordered_map<pair<int, int>, int, pair_hash> mp;
        vector<int> d(n + 1);
        for (auto& e : edges) {
            mp[make_pair(min(e[0], e[1]), max(e[0], e[1]))]++;
            d[e[0]]++, d[e[1]]++;
        }
        vector<int> incident;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                // cout << d[i] << ' ' << d[j] << ' ' << mp[make_pair(i, j)] <<
                // '\n';
                incident.push_back(d[i] + d[j] - mp[make_pair(i, j)]);
            }
        }
        sort(incident.begin(), incident.end());
        int k = incident.size();
        vector<int> res;
        int m = queries.size();
        for(int i=0; i<m; i++){
            int cur = k - (upper_bound(incident.begin(), incident.end(), queries[i]) - incident.begin());
            res.push_back(cur);
        }
        return res;
    }
};

// 3, 4, 4, 4, 5, 5
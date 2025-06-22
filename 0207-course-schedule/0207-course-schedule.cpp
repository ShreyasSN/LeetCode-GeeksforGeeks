class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int> d(n, 0);
        vector<vector<int>> g(n);
        for (auto& e : p) {
            g[e[1]].push_back(e[0]);
            d[e[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (d[i] == 0) {
                q.push(i);
            }
        }
        int res = 0;
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                int cur = q.front();
                q.pop();
                res++;
                for (int& i : g[cur]) {
                    if (--d[i] == 0) {
                        q.push(i);
                    }
                }
            }
        }
        return res == n;
    }
};

// n -> #courses
// preR -> [a, b]
// b -> a
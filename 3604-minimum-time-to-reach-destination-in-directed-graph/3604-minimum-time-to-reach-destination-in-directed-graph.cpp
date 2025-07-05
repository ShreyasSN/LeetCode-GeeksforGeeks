class Solution {
    struct info {
        int v, s, t;
        info(int _v, int _s, int _t) { v = _v, s = _s, t = _t; }
    };

public:
    int minTime(int n, vector<vector<int>>& edges) {
        if(n == 1) return 0;

        vector<vector<info>> g(n);
        vector<int> vis(n, false);
        using T = pair<int,int>;
        priority_queue<T, vector<T>, greater<T>> q;

        for (auto& cur : edges) {
            g[cur[0]].push_back(info(cur[1], cur[2], cur[3]));

            if(cur[0] == 0) {
                q.push({cur[2], cur[1]});
            }
        }
        vis[0] = true;

        while (!q.empty()) {
            auto [time, u] = q.top();
            q.pop();

            time++;
            if(u == n-1) return time;

            if(vis[u]) continue;
            vis[u] = 1;

            for (info& cur : g[u]) {
                int v = cur.v, start = cur.s, end = cur.t;

                if(start <= time && time <= end) q.push({time, v});
                else if(start > time) q.push({start, v});
            }
        }
        return -1;
    }
};
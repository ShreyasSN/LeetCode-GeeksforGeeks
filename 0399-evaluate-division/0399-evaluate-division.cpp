class Solution {
public:
    double dijkstra (int &source, int &destination, int count, vector<vector<double>> adj){
        vector<double> dist(count, -1.0);
       dist[source] = 1.0; 

        priority_queue<pair<double, int>, vector<pair<double, int>>, less<>> pq;
        pq.push({1.0, source});

        while (!pq.empty()) {
            auto [currentDist, currentNode] = pq.top();
            pq.pop();

            if (currentNode == destination) {
                return currentDist;
            }

            for (int nextNode = 0; nextNode < count; ++nextNode) {
                if (adj[currentNode][nextNode] > 0 && dist[nextNode] == -1.0) {
                    double newDist = currentDist * adj[currentNode][nextNode];
                    dist[nextNode] = newDist;
                    pq.push({newDist, nextNode});
                }
            }
        }

        return -1.0; 
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> mp;
        int count = 0;
        
        for (const auto& eq : equations) {
            if (mp.find(eq[0]) == mp.end()) {
                mp[eq[0]] = count++;
            }
            if (mp.find(eq[1]) == mp.end()) {
                mp[eq[1]] = count++;
            }
        }
        vector<vector<double>> adj(count, vector<double>(count, -1.0));
        for (int i = 0; i < count; ++i) {
            adj[i][i] = 1.0;
        }
        for (int i = 0; i < equations.size(); ++i) {
            int u = mp[equations[i][0]];
            int v = mp[equations[i][1]];
            adj[u][v] = values[i];
            adj[v][u] = 1.0 / values[i];
        }

        vector<double> result;
        for (const auto& q : queries) {
            if (mp.find(q[0]) == mp.end() || mp.find(q[1]) == mp.end()) {
                result.push_back(-1.0);
            } else {
                int source = mp[q[0]];
                int destination = mp[q[1]];
                result.push_back(dijkstra(source, destination, count, adj));
            }
        }

        return result;
    }
};
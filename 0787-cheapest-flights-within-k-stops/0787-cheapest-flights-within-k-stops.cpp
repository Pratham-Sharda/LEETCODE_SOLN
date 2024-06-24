class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Initialize adjacency list as a vector of vectors of pairs
        vector<vector<pair<int, int>>> adj(n);

        for (auto& i : flights) {
            int from = i[0];
            int to = i[1];
            int wt = i[2];
            adj[from].push_back({to, wt});
        }

        // Distance vector to store the minimum distance to each node
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // Queue to store the current cost and the current node
        queue<pair<int, int>> q;
        q.push({0, src});

        int steps = 0;

        // BFS to explore up to k stops
        while (!q.empty() && steps <= k) {
            int size = q.size();
            vector<int> temp_dist = dist; // Temporary distance vector to update after each level

            while (size--) {
                auto node = q.front();
                q.pop();
                int curr = node.second;
                int wt = node.first;

                for (auto& adjn : adj[curr]) {
                    if (dist[adjn.first] > wt + adjn.second) {
                        temp_dist[adjn.first] = wt + adjn.second;
                        q.push({wt + adjn.second, adjn.first});
                    }
                }
            }

            dist = temp_dist; // Update the main distance vector
            steps++;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

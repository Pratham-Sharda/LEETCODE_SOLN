class Solution {
public:
    int mod = 1e9+7;

    int countPaths(int n, vector<vector<int>>& roads) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dis(n, INT_MAX);
        vector<int> ways(n, 0);
        vector<vector<pair<int, int>>> adj(n);

        for (int i = 0; i < roads.size(); i++) {
            int from = roads[i][0];
            int to = roads[i][1];
            int wei = roads[i][2];
            adj[from].push_back({to, wei});
            adj[to].push_back({from, wei});  // Since roads are bidirectional
        }
        ways[0] = 1;
        dis[0] = 0;

        pq.push({0, 0});

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();  // Remove the processed element
            int u = curr.second;
            int distance = curr.first;

            for (auto& nbr : adj[u]) {
                int v = nbr.first;
                int wt = nbr.second;

                int newwt = wt + distance;
                if (newwt == dis[v]) {
                    ways[v] = (ways[v] + ways[u]) % mod;
                } else if (newwt < dis[v]) {
                    dis[v] = newwt;
                    ways[v] = ways[u];
                    pq.push({newwt, v});
                }
            }
        }

        return ways[n-1];
    }
};

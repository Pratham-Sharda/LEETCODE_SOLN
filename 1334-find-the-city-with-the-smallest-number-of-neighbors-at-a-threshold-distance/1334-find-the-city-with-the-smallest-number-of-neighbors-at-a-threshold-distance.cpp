class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> grid(n, vector<int>(n, 1e7));
        
        // Set the diagonal to 0 (distance to self is 0)
        for (int i = 0; i < n; ++i) {
            grid[i][i] = 0;
        }

        // Populate the grid with the given edges
        for (auto& edge : edges) {
            int from = edge[0];
            int to = edge[1];
            int wt = edge[2];

            grid[from][to] = wt;
            grid[to][from] = wt;
        }

        // Floyd-Warshall algorithm to find the shortest paths
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][k] + grid[k][j] < grid[i][j]) {
                        grid[i][j] = grid[i][k] + grid[k][j];
                    }
                }
            }
        }

        int mini = INT_MAX;
        int city = -1;

        // Find the city with the smallest number of reachable cities within the distance threshold
        for (int i = 0; i < n; ++i) {
            int ctr = 0;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] <= distanceThreshold) {
                    ctr++;
                }
            }
            // Update the city with the smallest number of reachable cities
            if (ctr <= mini) {
                mini = ctr;
                city = i;
            }
        }

        return city;
    }
};

class Solution {
public:
    int find(vector<int>& parent, int node) {
        // Path compression in find function
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = find(parent, parent[node]);
    }

    void uni(vector<int>& parent, vector<int>& rank, int u, int v) {
        // Find the roots of the nodes
        int pu = find(parent, u);
        int pv = find(parent, v);
        int ru = rank[pu];
        int rv = rank[pv];
        
        // Union by rank
        if (ru < rv) {
            parent[pu] = pv;
        } else if (rv < ru) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int maxrow = 0;
        int maxcol = 0;

        // Find the maximum row and column values
        for (auto i : stones) {
            maxrow = max(maxrow, i[0]);
            maxcol = max(maxcol, i[1]);
        }

        // Initialize the parent and rank vectors
        vector<int> parent(maxrow + maxcol + 2, 0);
        vector<int> rank(maxrow + maxcol + 2, 0);

        // Set each element to be its own parent
        for (int i = 0; i < parent.size(); i++) {
            parent[i] = i;
        }

        // Perform union operations
        for (auto i : stones) {
            int row = i[0];
            int col = i[1] + maxrow+1; // This ensures no overlap between rows and columns

            uni(parent, rank, row, col);
        }

        // Count the number of connected components
        int ctr = 0;
        for (int i = 0; i < parent.size(); i++) {
            if (find(parent, i) == i && rank[i]>0) {
                ctr++;
            }
        }

        // The result is the number of stones minus the number of connected components
        return stones.size() - ctr;
    }
};

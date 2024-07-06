class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 0) return mat;
        int m = mat[0].size();
        
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;
        
        // Initialize the queue with all zero cells and set their distances to zero
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        // Perform BFS
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for (int i = 0; i < 4; ++i) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];
                
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                    if (ans[newRow][newCol] > ans[row][col] + 1) {
                        ans[newRow][newCol] = ans[row][col] + 1;
                        q.push({newRow, newCol});
                    }
                }
            }
        }
        
        return ans;
    }
};

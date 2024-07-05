class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        // Add the two ends of the stick to the cuts list and sort it
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        int m = cuts.size();
        
        // Initialize the dp table
        vector<vector<int>> dp(m, vector<int>(m, 0));
        
        // Fill the dp table
        for (int length = 2; length < m; ++length) {  // length is the distance between i and j
            for (int i = 0; i < m - length; ++i) {
                int j = i + length;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], cuts[j] - cuts[i] + dp[i][k] + dp[k][j]);
                }
            }
        }
        
        return dp[0][m - 1];
    }
};
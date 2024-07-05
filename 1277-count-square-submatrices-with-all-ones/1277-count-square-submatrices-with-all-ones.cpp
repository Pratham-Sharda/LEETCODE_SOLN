class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>> dp=matrix;

        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(dp[i-1][j-1] && dp[i-1][j] && dp[i][j-1] && matrix[i][j]){
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                }
            }
        }

        int sum=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                sum+=dp[i][j];
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }

        return sum;
    }
};
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        auto it=triangle.back();
        int n=it.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        dp[0][0]=triangle[0][0];

        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                int diagonal=1e9;
                int up=1e9;

                if(j>0){
                    diagonal=dp[i-1][j-1]+triangle[i][j];
                }
                if(i>j){
                    up=dp[i-1][j]+triangle[i][j];
                }

                dp[i][j]=min(diagonal,up);
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            mini=min(mini,dp[n-1][i]);
        }

        return mini;
    }
};
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();

        int delcol[]={-1,0,1};
        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int i=0;i<n;i++){
            dp[0][i]=matrix[0][i];
            cout<<dp[0][i]<<" ";
        }
        cout<<endl;
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){

                int mini=1e9;

                for(int k=0;k<3;k++){
                    int newcol=j+delcol[k];

                    if(newcol>=0 && newcol<n ){
                        mini=min(mini,dp[i-1][newcol]+matrix[i][j]);
                    }
                }

                dp[i][j]=mini;
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        int ans=1e9;
        for(int i=0;i<n;i++){
            ans=min(ans,dp[n-1][i]);
        }

        return ans;
    }
};
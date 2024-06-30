class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,0));

        for(int i=0;i<amount+1;i++){
            if(i%coins[0]==0){
                dp[0][i]=1;
                // cout<<dp[0][i]<<".";
            }
            
        }
        // cout<<endl;

        for(int i=1;i<coins.size();i++){
            for(int j=0;j<amount+1;j++){

                int nottake=0+dp[i-1][j];
                int take=0;
                if(j>=coins[i]){
                    take=dp[i][j-coins[i]];
                }

                dp[i][j]=(take+nottake);
                // cout<<dp[i][j]<<".";
            }
            // cout<<endl;
        }

        return dp[coins.size()-1][amount];
    }
    int change(int amount, vector<int>& coins) {
        return coinChange(coins,amount);
    }
};
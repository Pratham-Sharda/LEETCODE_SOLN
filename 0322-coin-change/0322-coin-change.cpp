class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,0));

        for(int i=0;i<amount+1;i++){
            if(i%coins[0]==0){
                dp[0][i]=i/coins[0];
            }else{
                dp[0][i]=1e9;
            }
        }

        for(int i=1;i<coins.size();i++){
            for(int j=0;j<amount+1;j++){

                int nottake=0+dp[i-1][j];
                int take=1e9;
                if(j>=coins[i]){
                    take=1+dp[i][j-coins[i]];
                }

                dp[i][j]=min(take,nottake);
            }
        }

        if(dp[coins.size()-1][amount]>=1e9){
            return -1;
        }else{
            return dp[coins.size()-1][amount];
        }
    }
};
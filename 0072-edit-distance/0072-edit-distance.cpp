class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        if(n==0){
            return m;
        }if(m==0){
            return n;
        }
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=0;i<n+1;i++){
            dp[i][0]=i;
        }
        for(int j=0;j<m+1;j++){
            dp[0][j]=j;
        }

        dp[0][0]=0;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    int add=1+dp[i][j-1];
                    int remove=1+dp[i-1][j];
                    int replace=1+dp[i-1][j-1];

                    dp[i][j]=min(add,min(remove,replace));
                }
            }
        }


        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[n][m];
    }
};
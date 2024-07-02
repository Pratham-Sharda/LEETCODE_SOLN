class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<double>> dp(n+1,vector<double>(m+1,0));

        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        // int common=dp[n][m];

        return (int)dp[n][m];
        // string ans="";
        // int i=n;int j=m;

        // while(i>0 && j>0){
        //     if(s[i-1]==t[j-1]){
        //         ans=ans+s[i-1];i--;j--;
        //     }else{
        //         if(dp[i-1][j]>dp[i][j-1]){
        //             ans=ans+s[i-1];
        //             i--;
        //         }else{
        //             ans+=t[j-1];
        //             j--;
        //         }
        //     }
        // }

        // while(i>0){
        //     ans+=s[i-1];i--;
        // }
        // while(j>0){
        //     ans+=t[j-1];j--;
        // }

        // return ans;
    }
};
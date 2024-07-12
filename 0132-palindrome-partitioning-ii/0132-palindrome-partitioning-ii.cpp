class Solution {
public:
    bool ispal(string & s,int i,int j){
        // int i=0;
        // int j=s.length()-1;
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;j--;
        }
        return true;
    }
    int minCut(string s) {
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=0;
            }else{
                dp[i][i+1]=1;
            }
        }
        for(int len=3;len<=n;len++){
            for(int i=0;i<n-len+1;i++){
                int j=i+len-1;

                if(ispal(s,i,j)){
                    dp[i][j]=0;
                    continue;
                }else{
                    int maxi=1e9;
                    for(int k=i;k<j;k++){
                        maxi=min(maxi,1+dp[i][k]+dp[k+1][j]);
                    }
                    dp[i][j]=maxi;
                }
            }
        }

        return dp[0][n-1];

    }
};
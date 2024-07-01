class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        int table[n+1][m+1];
        
        for (int i=0;i<=n;i++){
            table[i][0]=0;
        }
        for (int i=0;i<=m;i++){
            table[0][i]=0;
        }

        for (int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    table[i][j]=table[i-1][j-1] + 1;
                }else{
                    int alpha=max(table[i-1][j],table[i][j-1]);
                    table[i][j]=alpha;
                }

            }
        }
        return table[n][m];
    }
};
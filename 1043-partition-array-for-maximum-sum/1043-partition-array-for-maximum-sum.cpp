class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();

        vector<int> dp(n+1,0);

        for(int i=n-1;i>=0;i--){
            int maxval=-1;
            int maxink=-1;
            for(int j=i;j<n && j-i+1<=k;j++){
                maxink=max(maxink,arr[j]);
                int curval=maxink*(j-i+1)+dp[j+1];
                maxval=max(maxval,curval);
            }
            dp[i]=maxval;
        }
        return dp[0];
    }
};
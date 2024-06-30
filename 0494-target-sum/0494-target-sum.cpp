class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int tot=0;
        for(auto i:nums){
            tot+=i;
        }

        if((tot-target)%2 || tot<target){
            return 0;
        }
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>((tot-target)/2+1,0));

        dp[0][0]=1;

        for(int i=1;i<n+1;i++){
            // idx=i-1;
            for(int j=0;j<(tot-target)/2+1;j++){
                int no=dp[i-1][j];
                int take=0;
                if(j>=nums[i-1]){
                    take=dp[i-1][j-nums[i-1]];
                }

                dp[i][j]=take+no;
                cout<<dp[i][j]<<".";
            }
            cout<<endl;
        }

        return dp[n][(tot-target)/2];
    }
};
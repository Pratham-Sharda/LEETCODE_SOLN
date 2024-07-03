class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> ctr(n,1);
        int maxi=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        ctr[i]=ctr[j];
                    }else if(dp[j]+1==dp[i]){
                        ctr[i]+=ctr[j];
                    }
                }
            }
            if(dp[maxi]<dp[i]){
                maxi=i;
            }

        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]==dp[maxi]){
                ans+=ctr[i];
            }
        }

        return ans;
    }
};
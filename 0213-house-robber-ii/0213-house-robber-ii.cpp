class Solution {
public:
    long long solve(vector<int> & arr){
        int k=arr.size();
        vector<long long> dp(k,0);
        if(k==1){
            return arr[0];
        }
        dp[0]=arr[0];
        dp[1]=max(arr[0],arr[1]);

        for(int j=2;j<k;j++){
            int take=arr[j]+dp[j-2];
            int nottake=dp[j-1];
            dp[j]=max(take,nottake);
        }
        return dp[k-1];
    }
    int rob(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;

        int n=nums.size();

        for(int i=0;i<n;i++){
            if(i!=n-1)arr1.push_back(nums[i]);
            if(i!=0)arr2.push_back(nums[i]);
        }

        long long ans1=solve(arr1);
        long long ans2=solve(arr2);

        return max(ans1,ans2);
    }
};
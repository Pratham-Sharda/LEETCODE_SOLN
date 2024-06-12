class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        for(int j=1;j<n;j++){
            if(nums[i]==0){
                i++;
                continue;
            }
            if(nums[j]==0){
                swap(nums[j],nums[i]);
                i++;
            }
        }
        int k=nums.size()-1;

        for(int j=0;j<=k;j++){
            if(nums[k]==2){
                k--;
                j--;
                continue;
            }
            if(nums[j]==2){
                swap(nums[j],nums[k]);
                k--;
            }
        }
    }
};
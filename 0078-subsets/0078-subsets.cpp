class Solution {
public:
    void all_ans(vector<int> nums,vector<int> opt,vector<vector<int>>& ans){
        if(nums.size()==0){
            ans.push_back(opt);
            return;
        }
        int first=nums[0];
        nums.erase(nums.begin()+0);
        vector<int>op1=opt;
        op1.push_back(first);
        vector<int>op2=opt;
        all_ans(nums,op1,ans);
        all_ans(nums,op2,ans);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        all_ans(nums,output,ans);
        return ans;
    }
};
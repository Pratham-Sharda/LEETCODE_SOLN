class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> dp;

        for(int i=0;i<names.size();i++){
            dp.push_back({heights[i],names[i]});
        }

        sort(dp.begin(),dp.end());
        vector<string> ans;
        for(int i=dp.size()-1;i>=0;i--){
            ans.push_back(dp[i].second);
        }

        return ans;
    }
};
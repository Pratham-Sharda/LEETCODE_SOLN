class Solution {
public:
    bool wordBreak(string s, vector<string>& dictionary) {
        int n=dictionary.size();
        unordered_set<string> mpp;
        for(int i=0;i<n;i++){
            mpp.insert(dictionary[i]);
        }
        
        int x=s.length();
        
        vector<int> dp(x+1,0);
        dp[x]=1;
        for(int i=x-1;i>=0;i--){
            for(int j=i+1;j<=x;j++){
                if(mpp.find(s.substr(i,j-i))!=mpp.end() && dp[j]){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[0];
    }
};
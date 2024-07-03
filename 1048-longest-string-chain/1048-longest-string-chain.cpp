class Solution {
public:
    
    bool check(string& s1, string &s2){
        if(s1.length()-s2.length()!=1){
            return false;
        }
        int i=0;
        int j=0;
        while(i<s1.length() && j<s2.length()){
            if(s1[i]==s2[j]){
                i++;j++;
            }else{
                i++;
            }
        }
        if(j==s2.length()){
            return true;
        }
        return false;
    }
    static bool comp(string& s1,string & s2){
        return s1.length()<s2.length();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int maxi=0;
        int n=words.size();
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(words[i],words[j]) && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                }
            }

            if(dp[maxi]<dp[i]){
                maxi=i;
            }
        }

        return dp[maxi];

    }
};
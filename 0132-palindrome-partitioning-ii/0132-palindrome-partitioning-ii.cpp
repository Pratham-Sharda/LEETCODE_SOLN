class Solution {
public:
    bool isPalindrome(const string& s, int start, int end) {
    // Check bounds
    if (start < 0 || end >= s.length() || start > end) {
        return false; // Invalid indices
    }
    
    // Iterate over the substring and check palindrome property
    while (start < end) {
        if (s[start] != s[end]) {
            return false; // Not a palindrome
        }
        start++;
        end--;
    }
    
    return true; // It's a palindrome
}
    int minCut(string s) {
        int n=s.length();
        vector<int> dp(n+1,0);

        for(int i=n-1;i>=0;i--){
            int mini=1e9;
            for(int j=i;j<n;j++){
                if(isPalindrome(s,i,j)){
                    mini=min(1+dp[j+1],mini);
                }
            }

            dp[i]=mini;
        }

        return dp[0]-1;
    }
};
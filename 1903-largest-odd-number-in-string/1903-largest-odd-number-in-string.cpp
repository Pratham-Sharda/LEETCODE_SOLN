class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        int ans=-1;
        for(int i=n-1;i>=0;i--){
            int val=num[i]-'0';
            if(val%2){
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};
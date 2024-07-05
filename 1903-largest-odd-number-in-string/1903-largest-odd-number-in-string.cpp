class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        int ans=-1;
        for(int i=n-1;i>=0;i--){
            int val=num[i]-'0';
            if(val%2){
                ans=i;
                break;
            }
        }
        string r="";
        if(ans==-1){
            return "";
        }else{
            for(int i=0;i<=ans;i++){
                r+=num[i];
            }
        }

        return r;
    }
};
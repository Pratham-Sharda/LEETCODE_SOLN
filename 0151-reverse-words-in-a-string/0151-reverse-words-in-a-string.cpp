class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        string r="";
        vector<string> words;
        string temp="";
        for(int i=0;i<n;i++){
            if(s[i]==' ' ){
                continue;
            }
            if(s[i]!=' '){
                if((i+1<n && s[i+1]==' ') || (i==n-1)){
                    temp+=s[i];
                    words.push_back(temp);
                    temp="";
                }else{
                    temp+=s[i];
                }
            }
        }
        int k=words.size();
        for(int i=k-1;i>=0;i--){
            r = r + words[i] +" ";
        }

        int x=r.length();
        r.erase(x-1,1);
        return r;
        
    }
};
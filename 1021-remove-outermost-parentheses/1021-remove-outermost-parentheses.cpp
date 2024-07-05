class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.length();
        if(s[0]==')'){
            return "";
        }
        int ctr=1;
        int start=0;
        int end=-1;
        vector<pair<int,int>> vec;
        for(int i=1;i<n;i++){
            
            if(s[i]=='('){
                ctr++;
            }else if(s[i]==')'){
                ctr--;
                if(ctr==0){
                    end=i;
                    vec.push_back({start,end});
                    start=i+1;
                }
            }
        }
        
        for(int i=vec.size()-1;i>=0;i--){
            int back=vec[i].second;
            int front=vec[i].first;
            s.erase(back,1);
            s.erase(front,1);
        }
        return s;

    }
};
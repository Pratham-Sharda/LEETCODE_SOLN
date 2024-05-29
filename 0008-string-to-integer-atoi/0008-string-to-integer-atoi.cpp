class Solution {
public:
    int stooi(string s){
        if(s[0]=='-'){
            s.erase(s.begin()+0);
            long long int temp=0;
        for(int i=0;i<s.length();i++){
            if(temp>(INT_MAX -(s[i]-'0'))/10){return INT_MIN;}
            temp=temp*10+(s[i]-'0');
        }
        if(temp<=INT_MIN){
            return INT_MIN;
        }
        return -temp;
        }else{
        if(s[0]=='+') {s.erase(s.begin()+0);}   
        long long int temp=0;
        for(int i=0;i<s.length();i++){
             if(temp>(INT_MAX -(s[i]-'0'))/10){return INT_MAX;}
            temp=temp*10+(s[i]-'0');
        }
        if(temp>=INT_MAX){
            return INT_MAX;
        }
        return temp;}
    }
    void solve(string s,string curr,int& ans,int which){

        if(s.length()==0){
            ans=stooi(curr);
            return;
        }else if(s[0]==' ' && !which){
            s.erase(s.begin()+0);
            solve(s,curr,ans,1);
            return;
        }
        else if(s[0]=='-' && !which){
            curr.push_back('-');
            s.erase(s.begin()+0);
            cout<<curr<<endl;
            solve(s,curr,ans,1);
            return;
        }else if(s[0]=='+' && !which){
            curr.push_back('+');
            s.erase(s.begin()+0);
            cout<<curr<<endl;
            solve(s,curr,ans,1);
            return;
        }

        else if(!isdigit(s[0])){
            ans=stooi(curr);
            return;
        }

        // string otp=s;
        curr.push_back(s[0]);
        s.erase(s.begin()+0);
        solve(s,curr,ans,1);
        return;

    }
    int myAtoi(string s) {
        int ans=-1;
        while(s[0]==' '){
            s.erase(s.begin()+0);
        }
        solve(s,"",ans,0);
        return ans;
        // return INT_MAX;
    }
};
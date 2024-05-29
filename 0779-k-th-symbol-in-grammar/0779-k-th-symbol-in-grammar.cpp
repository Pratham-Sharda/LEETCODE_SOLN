class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1 && k==1){
            return 0;
        }
        int prev=kthGrammar(n-1,ceil(double(k)/2));

        if(prev){
            if(k/2==ceil(double(k)/2)){
                return 0;
            }else{return 1;}
        }else{
             if(k/2==ceil(double(k)/2)){
                return 1;
            }else{return 0;}
        }

    }
};
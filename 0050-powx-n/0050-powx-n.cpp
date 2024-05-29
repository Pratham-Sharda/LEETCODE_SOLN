class Solution {
public:
    double ansgen(double x,int n){
        if(n==0){
            return 1;
        }else if(n==1){
            return x;
        }

        if(n%2==0){
            double po=x*x;     
            return ansgen(po,n/2);
        }    
        else{
            double po=x*x; 
            return ansgen(po,n/2)*x;   
        }
        return -1;
    }
    double myPow(double x, int n) {
        int sign = (n >= 0) ? 1 : -1;
        if(sign==1){
            return ansgen(x,n);
        }else{
            return 1/ansgen(x,n);
        }
        
        
    }
};
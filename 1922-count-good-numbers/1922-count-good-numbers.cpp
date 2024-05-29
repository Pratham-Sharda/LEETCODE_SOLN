class Solution {
public:
    long long poe(long long k,long long n){
        long long mo=pow(10,9)+7;
        if(n==1){
            return (k%mo);
        }else if(n==0){
            return (long long)(1);
        }

        if(n%2==0){
            long long dou=(k%mo)*(k%mo);
            return (poe(dou,n/2))%mo;
        }else{
            long long dou=(k%mo)*(k%mo);
            return (poe(dou,n/2))%mo*(k%mo);
        }
        return -1;
    }
    int countGoodNumbers(long long n) {
        long long evenP=(long long)n/2+(long long)n%2;
        long long oddP=(long long)n/2;
        cout<<evenP<<" "<<oddP<<endl;
        long long ansE=poe((long long)5,evenP);
        
        long long ansO=poe((long long)4,oddP);
        cout<<ansE<<" "<<ansO<<endl;
        long long mo=poe(10,9)+7;
        cout<<mo<<endl;
        // ansE=ansE%mo;
        // ansO=ansO%mo;
        long long final=((ansE%mo)*(ansO%mo))%mo;
        cout<<final<<endl;
        return (int)final;

        
    }
};
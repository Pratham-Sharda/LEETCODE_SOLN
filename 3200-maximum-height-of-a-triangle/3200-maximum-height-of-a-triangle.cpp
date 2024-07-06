class Solution {
public:
    int dol(int red,int blue){
        int d=0;
        while(red>=0 && blue>=0){
            int rd=d+1;
            int bd=d+2;
            red=red-rd;
            if(red<0){
                return d;
            }
            blue=blue-bd;
            if(blue<0){
                return d+1;
            }
            d=d+2;
        }
        return d;
    }
    int maxHeightOfTriangle(int red, int blue) {
        int r=dol(red,blue);
        int b=dol(blue,red);

        return max(r,b);

    }
};
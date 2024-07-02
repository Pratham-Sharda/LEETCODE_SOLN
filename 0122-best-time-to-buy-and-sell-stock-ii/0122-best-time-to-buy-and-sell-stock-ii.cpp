class Solution {
public:
    int maxProfit(vector<int>& price) {
        
        int curr=0;
        int maxprofit=0;
        int buy=0;
        int sell=0;
        for(int i=1;i<price.size();i++){
            int profit=price[i]-price[buy];
            if(profit<0){
                buy=i;
                sell=i;
            }else if(profit>=0){
                if(price[i]>price[sell]){
                    maxprofit+=price[i]-price[sell];
                    sell=i;
                    // buy=i+1;
                }else if(price[i]<price[sell]){
                    buy=i;
                    sell=i;
                }
            }
        }
        return maxprofit;
    }
    
};
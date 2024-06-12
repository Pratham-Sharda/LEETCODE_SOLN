class Solution {
public:
    bool checkcons(vector<int> & val){
        for(int i=0;i<val.size()-1;i++){
            if(val[i]+1!=val[i+1]){
                return false;
            }
        }
        return true;
    }
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> mpp;
        for(int i:hand){
            mpp[i]++;
        }
        priority_queue<int,vector<int>,greater<int>> minh;
        for(auto i=mpp.begin();i!=mpp.end();i++){
            minh.push(i->first);
        }
        while(!minh.empty()){
            // int v1=minh.top();minh.pop();
            // if(minh.empty()){
            //     return false;
            // }
            // int v2=minh.top();minh.pop();
            // if(minh.empty()){
            //     return false;
            // }
            // int v3=minh.top();minh.pop();
            vector<int> value;
            value.push_back(minh.top());minh.pop();
            for(int i=1;i<groupSize;i++){
                if(minh.empty()){
                    return false;
                }
                value.push_back(minh.top());minh.pop();
            }
            for(int i=0;i<groupSize;i++){
                mpp[value[i]]--;
            }
            // mpp[v1]--;mpp[v2]--;mpp[v3]--;
            for(int i=0;i<value.size();i++){
                if(mpp[value[i]]){
                    minh.push(value[i]);
                }
            }
            if(!checkcons(value)){
                return false;
            }
            // if(mpp[v1]){
            //     minh.push(v1);
            // }
            
            // if(mpp[v2]){
            //     minh.push(v2);
            // }
            
            // if(mpp[v3]){
            //     minh.push(v3);
            // }

        }

        return true;
    }
};
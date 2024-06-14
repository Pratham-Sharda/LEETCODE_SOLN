class compare{
    public :
    bool operator()(pair<int,int>a,pair<int,int>b){
        return a.second>b.second;
    }
};
class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int ,int> mpp;
        for(int i:nums){
            mpp[i]++;
        }
        int ctr=0;
        priority_queue<pair<int,int> ,vector<pair<int,int>>,compare> minheap;
        for(auto & i:mpp){
            if(minheap.size()<k){
                minheap.push(i);
            }else if(i.second>minheap.top().second){
                minheap.pop();
                minheap.push(i);
            }
        }
        vector<int> ans;
        while(!minheap.empty()){
            pair<int,int> cur=minheap.top();
            minheap.pop();
            ans.push_back(cur.first);

        }
        return ans;
    }
};
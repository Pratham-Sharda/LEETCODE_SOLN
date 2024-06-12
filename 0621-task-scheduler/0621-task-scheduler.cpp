class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       vector<int> freq(26,0);
        for(char& ch:tasks){
            freq[ch-'A']++;
        } 
        priority_queue<int> maxheap;
        for(int i:freq){
            if(i>0){
            maxheap.push(i);}
        }
        int time=0;
        while(!maxheap.empty()){
            vector<int> tempo;
            for(int i=0;i<n+1;i++){
                if(!maxheap.empty()){
                    int cur=maxheap.top();
                    maxheap.pop();
                    cur--;
                    tempo.push_back(cur);
                }
            }
            for(int i=0;i<tempo.size();i++){
                if(tempo[i]>0){maxheap.push(tempo[i]);}
                
            }

            if(!maxheap.empty()){
                time+=n+1;
            }else{
                time+=tempo.size();
            }

        }
        return time;
    }
};
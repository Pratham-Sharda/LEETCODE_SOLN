class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1, INT_MAX);
        vector<vector<pair<int, int>>> adj(n+1);

        for (auto i : times) {
            int u = i[0];
            int v = i[1];
            int wt = i[2];

            adj[u].push_back({v, wt});
        }

        queue<pair<int,int>> q;
        q.push({k,0});
        dist[k]=0;

        while(!q.empty()){
            int size=q.size();

            while(size--){
                int u=q.front().first;
                int wt=q.front().second;
                q.pop();

                for(auto near:adj[u]){
                    int v=near.first;
                    int d=near.second;

                    if(dist[v]> d+wt){
                        dist[v]=d+wt;
                        q.push({v,d+wt});
                    }
                }
            }
        }

        int mini=INT_MIN;
        for(int i=1;i<dist.size();i++){
            if(dist[i]==INT_MAX){
                return -1;
            }else{
                mini=max(mini,dist[i]);
            }
        }

        return mini;
    }
};
class Solution {
public:
    void bfs(int node,vector<int>& visited,vector<vector<int>>& lis){
        visited[node]=1;
        queue<int> q;
        q.push(node);

        while(!q.empty()){
            int vurr=q.front();
            q.pop();
            for(auto i:lis[vurr]){
                if(!visited[i]){
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> lis(n);

        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(isConnected[i][j]){
                    lis[i].push_back(j);
                }
                
            }
        }
        
        int ctr=0;
        vector<int> visited(n,0);

        for(int i=0;i<n;i++){
            if(!visited[i]){
                bfs(i,visited,lis);
                ctr++;
            }
        }

        return ctr;
    }
};
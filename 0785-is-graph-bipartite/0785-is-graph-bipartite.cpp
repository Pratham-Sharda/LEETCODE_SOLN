class Solution {
public:
    bool bfs_bi(int node,vector<int> & visited, vector<int> &colour,vector<vector<int>>& graph){
        queue<vector<int>> q; //nodeno.,parent,colour(1,0)
        q.push({node,-1,0});
        visited[node]=1;
        colour[node]=0;

        while(!q.empty()){
            auto curr=q.front();q.pop();
            int curnode=curr[0];
            int parent=curr[1];
            int curcol=curr[2];

            for(auto i:graph[curnode]){
                if(i==parent){
                    continue;
                }
                if(!visited[i]){
                    visited[i]=1;
                    colour[i]=!curcol;
                    q.push({i,curnode,!curcol});
                }else if(colour[i]==curcol){
                    return false;
                }
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> visited(n,0);
        vector<int> colour(n,-1);

        for(int i=0;i<=n-1;i++){
            if(!visited[i]){
                if(!bfs_bi(i,visited,colour,graph)){
                    return false;
                }
            }
        }
        return true;
        
    }
};
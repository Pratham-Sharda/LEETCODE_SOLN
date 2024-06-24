class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return -1;
        }
        if(n==1){return 1;}
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        queue<vector<int>> q;
        dist[0][0]=1;
        q.push({dist[0][0],0,0});

        while(!q.empty()){
            auto node=q.front();q.pop();
            int dis=node[0];
            int i=node[1];
            int j=node[2];


            for(int delrow=-1;delrow<=1;delrow++){
                for(int delcol=-1;delcol<=1;delcol++){
                    int nr=i+delrow;
                    int nc=j+delcol;
                    if(nr==n-1 && nc==n-1){
                        return dis+1;
                    }
                    if(nr>=0 && nr<n &&nc>=0 && nc<n && grid[nr][nc]==0 && dist[nr][nc]>dis+1){
                        dist[nr][nc]=dis+1;
                        q.push({dis+1,nr,nc});
                    }
                }
            }
        }

        if(dist[n-1][n-1]==INT_MAX){
            return -1;
        }else{
            return dist[n-1][n-1];
        }
    }
};
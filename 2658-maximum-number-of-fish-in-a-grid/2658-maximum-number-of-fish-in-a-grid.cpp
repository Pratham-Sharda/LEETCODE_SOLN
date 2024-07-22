class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& visited){
        visited[i][j]=1;
        int fish=grid[i][j];
        int n=grid.size();
        int m=grid[0].size();
        
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int k=0;k<4;k++){
            int nr=i+delrow[k];
            int nc=j+delcol[k];
            if(nr>=0 && nc>=0 &&nr<n &&nc<m && !visited[nr][nc] && grid[nr][nc]>0){
                fish+=dfs(nr,nc,grid,visited);
            }
        }
        return fish;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));

        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]>0){
                    int fish=dfs(i,j,grid,visited);
                    maxi=max(maxi,fish);
                }
            }
        }
        return maxi;
    }
};
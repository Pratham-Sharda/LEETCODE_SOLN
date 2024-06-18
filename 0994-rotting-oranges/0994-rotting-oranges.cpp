class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<int ,int> >q;
        for(int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    visited[i][j]=2;
                }
            }
        }
        int time = 0;
        while(!q.empty()){
            int curr=q.size();
            for (int i=0;i<curr;i++){
                pair<int,int> cell=q.front();
                q.pop();
                int row=cell.first;
                int col=cell.second;
                int delrow[]={-1,0,+1,0};
                int delcol[]={0,+1,0,-1};
                for(int itr=0;itr<4;itr++){
                    int nrow=row+delrow[itr];
                    int ncol=col+delcol[itr];
                    if(nrow>=0 && nrow<n &&ncol>=0 &&ncol<m && grid[nrow][ncol]==1 && visited[nrow][ncol]!=2){
                        q.push({nrow,ncol});
                        visited[nrow][ncol]=2;
                    }
                }
                
            }
            time++;
        }

        for(int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if(grid[i][j]==1 && visited[i][j]!=2){
                    return -1;
                }
            }
        }

        if(time<1){
            return 0;
        }else{
            return time-1
        }
    }
};
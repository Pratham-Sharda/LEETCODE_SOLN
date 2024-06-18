class Solution {
public:
    int find(int row,int col,vector<vector<int>> & mat, vector<vector<int>> & visited){
        visited[row][col]=3;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{row,col}});

        while(!q.empty()){
            int row=q.front().second.first;
            int col=q.front().second.second;
            int dis=q.front().first;
            int val=mat[row][col];
            q.pop();
            if(val==0){
                return dis; 
            }else{
                int delrow[]={-1,0,1,0};
                int delcol[]={0,1,0,-1};
                for(int i=0;i<4;i++ ){
                    int nrow=row+delrow[i];
                    int ncol=col+delcol[i];
                    if(nrow>=0 && nrow<mat.size() && ncol>=0 &&ncol<mat[0].size()){
                        if(mat[nrow][ncol]==0){
                            return dis+1;
                        }else{
                            q.push({dis+1,{nrow,ncol}});
                        }
                    }
                }
            }



        }
        return -1;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        
        for(int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                    visited[i][j]=8;
                    q.push({{i,j},0});
                }else{
                    visited[i][j]=-1;
                }
            }
        }
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int dis=q.front().second;

            q.pop();
            for(int i=0;i<4;i++){
                int nr=row+delrow[i];
                int nl=col+delcol[i];
                if(nr>=0 && nr<mat.size() && nl>=0 &&nl<mat[0].size()){
                    if(visited[nr][nl]==8){
                            continue;
                    }else if(visited[nr][nl]==-1){
                        ans[nr][nl]=dis+1;
                        visited[nr][nl]=8;
                        q.push({{nr,nl},dis+1});
                    }
                }
            }

        }
        return ans;
    }
};
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

        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                vector<vector<int>> visited(n,vector<int>(m,0));
                ans[i][j]=find(i,j,mat,visited);
            }
        }
        return ans;
    }
};
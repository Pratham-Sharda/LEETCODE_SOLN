class Solution {
public:
    void bfs(int i,int j,vector<vector<int>> & board ,vector<vector<int>> & visi){
        visi[i][j]=-1;
        int n=board.size();
        int m=board[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;q.pop();

            for(int i=0;i<4;i++){
                int nr=r+delr[i];
                int nc=c+delc[i];

                if(nr>=0 &&nc>=0 &&nr<n && nc<m &&visi[nr][nc]==0 &&board[nr][nc]==1){
                    visi[nr][nc]=-1;
                    q.push({nr,nc});
                }
            }

        }
    }

    int numEnclaves(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> visi(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            if(board[i][0]==1){
                bfs(i,0,board,visi);
            }if(board[i][m-1]==1){
                bfs(i,m-1,board,visi);
            }
        }

        for(int i=0;i<m;i++){
            if(board[0][i]==1){
                bfs(0,i,board,visi);
            }if(board[n-1][i]==1){
                bfs(n-1,i,board,visi);
            }
        }

        int ctr=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==1 && visi[i][j]!=-1){
                    ctr++;
                }
            }
        }
        return ctr;
        
    }
};
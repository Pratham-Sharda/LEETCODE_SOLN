class Solution {
public:
    void dfs(int sr,int sc,int old,int color, vector<vector<int>> &ans,vector<vector<int>> &image,int delrow[],int delcol[]){
            ans[sr][sc]=color;
            int n=ans.size();
            int m=ans[0].size();
            for(int i=0;i<4;i++){
                int nrow=sr+delrow[i];
                int ncol=sc+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==old && ans[nrow][ncol]!=color){
                    dfs(nrow,ncol,old,color,ans,image,delrow,delcol);
                }
            }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans= image;
        int old=image[sr][sc];
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        dfs(sr,sc,old,color,ans,image,delrow,delcol);
        return ans;
    }
};
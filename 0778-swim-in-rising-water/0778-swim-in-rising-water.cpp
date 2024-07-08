class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> water(n,vector<int>(n,1e9));

        queue<pair<int,pair<int,int>>> q;
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        water[0][0]=grid[0][0];
        q.push({grid[0][0],{0,0}}); //{dist,{i,j}};
        while(!q.empty()){
            auto curr=q.front();
            int curtime=curr.first;
            int row=curr.second.first;
            int col=curr.second.second;q.pop();

            for(int i=0;i<4;i++){
                int newr=row+delr[i];
                int newc=col+delc[i];

                if(newr>=0 && newc>=0 &&newr<n && newc<n){
                    int maxtime=max(water[row][col],grid[newr][newc]);
                    if(water[newr][newc]>maxtime){
                        water[newr][newc]=maxtime;
                        q.push({maxtime,{newr,newc}});
                    }

                }
            }
        }

        return water[n-1][n-1];

    }
};
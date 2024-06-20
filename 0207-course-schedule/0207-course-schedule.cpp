class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            int from=prerequisites[i][1];
            int to=prerequisites[i][0];

            adj[from].push_back(to);
        }

        int ctr=0;
        queue<int> q;
        vector<int> indeg(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto node:adj[i]){
                indeg[node]++;
            }
        }
        for(int i=0;i<indeg.size();i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int cur=q.front();q.pop();
            ctr++;

            for(auto i:adj[cur]){
                indeg[i]--;
                if(indeg[i]==0){
                    q.push(i);
                }
            }
        }


        if(ctr<numCourses){
            return false;
        }else{
            return true;
        }
    }
};
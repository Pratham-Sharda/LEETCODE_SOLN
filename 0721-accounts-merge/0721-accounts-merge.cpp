class Solution {
public:
    int find(vector<int>& parent,int node){
	    if(parent[node]==node){
	        return node;
	    }
	    return parent[node]=find(parent,parent[node]);
	}
	
	void uni(vector<int> & parent, vector<int> &rank,int u, int v){
	    int pu=find(parent,u);
	    int pv=find(parent,v);
	    int ru=rank[pu];
	    int rv=rank[pv];
	    
	    if(ru<rv){
	        parent[pu]=pv;
	    }else if(rv<ru){
	        parent[pv]=pu;
	    }else{
	        parent[pv]=pu;
	        rank[pu]++;
	    }
	}
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        vector<int> parent(n,0);
        vector<int> rank(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        unordered_map<string,int> mpp;
        for(int i=0;i<n;i++){
            for( int j=1;j<accounts[i].size();j++){
                if(mpp.find(accounts[i][j])==mpp.end()){
                    mpp[accounts[i][j]]=i;
                }else{
                    uni(parent,rank,i,mpp[accounts[i][j]]);
                }
            }
        }

        vector<string> inter[n];

        for(auto i:mpp){
            string mail=i.first;
            int node =find(parent,i.second);
            inter[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for(int i=0;i<n;i++){
            if(inter[i].size()==0){
                continue;
            }
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            sort(inter[i].begin(),inter[i].end());
            for(int k=0;k<inter[i].size();k++){
                temp.push_back(inter[i][k]);
            }

            ans.push_back(temp);
        }


        return ans;
            
    }
};
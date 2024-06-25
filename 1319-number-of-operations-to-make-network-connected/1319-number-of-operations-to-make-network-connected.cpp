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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int ctr=n-1;
        if(ctr>connections.size()){
            return -1;
        }
        // vector<int> visited(n,0);
        vector<int> parent(n,0);
        vector<int> rank(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto i:connections){
            int u=i[0];
            int v=i[1];
            if(find(parent,u)!=find(parent,v)){
                ctr--;
                uni(parent,rank,u,v);
            }
        }

        return ctr;
    }
};
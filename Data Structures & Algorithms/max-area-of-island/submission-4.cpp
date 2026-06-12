class DSU{
public:
    vector<int>parent,size,rank;
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1);
        rank.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findParent(int node){
        if(node==parent[node]) return node;
        return parent[node]=findParent(parent[node]);
    }
    void unionBySize(int u,int v){
        int pu=findParent(u);
        int pv=findParent(v);
        if(pu==pv) return;
        if(size[pu]<size[pv]){//connect u to v 
            size[pv]=size[pv]+size[pu];
            parent[pu]=pv;
        }else{
            size[pu]=size[pu]+size[pv];
            parent[pv]=pu;
        }
    }
    void unionByRank(int u,int v){
        int pu=findParent(u);
        int pv=findParent(v);
        if(pu==pv) return;
        if(rank[pu]<rank[pv]){ //we shoould add the smaller rank 
            // to the larger 
            parent[pu]=pv;
           //so the smaller rank parent 
            // will be the larger rank node's ultimate parent 
            //rank wont change 
        }else if(rank[pu]>rank[pv]){
            parent[pv]=pu;
        }else{
            parent[pu]=pv;
            rank[pu]++;//we will increase the rank if both are equal
        }
    }
    int getSize(int node){
        int pnode=findParent(node);
        return size[pnode];
    }
};
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
         int m=grid.size();
        int n=grid[0].size();
        DSU dsu(m*n);
        int maxi=0;
        int dr[4]={-1,0,1,0};
        int dc[4]={0,-1,0,1};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    for(int k=0;k<4;k++){
                        int nrow=dr[k]+i;
                        int ncol=dc[k]+j;
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]==1){
                        dsu.unionBySize(i*n+j,nrow*n+ncol);
                    }
                }
                maxi=max(maxi,dsu.getSize(n*i+j));
            }
        }
    }
    return maxi;
    }
};

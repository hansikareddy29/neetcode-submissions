class Solution {
public:

    int numberOfConnected(vector<vector<int>>& grid,vector<vector<int>>& visited,int r,int c,int m,int n){
        int count=1;
        visited[r][c]=1;
        int dr[4]={-1,0,1,0};
        int dc[4]={0,-1,0,1};
        for(int i=0;i<4;i++){
            int nrow=dr[i]+r;
            int ncol=dc[i]+c;
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !visited[nrow][ncol] && grid[nrow][ncol]==1){
                count+=numberOfConnected(grid,visited,nrow,ncol,m,n);
            }
        }
        return count;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        int maxi=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    maxi=max(maxi,numberOfConnected(grid,visited,i,j,m,n));
                }
            }
        }
        return maxi;
    }
};

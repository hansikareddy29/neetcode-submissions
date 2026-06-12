class Solution {
public:


    void dfs(vector<vector<char>>& grid,vector<vector<bool>> &visited,int r,int c,int m,int n){
        visited[r][c]=1;
        int dr[4]={-1,0,1,0};
        int dc[4]={0,-1,0,1};
        for(int i=0;i<4;i++){
            int nrow=dr[i]+r;
            int ncol=dc[i]+c;
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !visited[nrow][ncol] && grid[nrow][ncol]=='1'){
                dfs(grid,visited,nrow,ncol,m,n);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        vector<vector<bool>>visited(m,vector<bool>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    dfs(grid,visited,i,j,m,n);
                    count++;
                }
            }
        }
        return count;
    }
};

// BFS approach of finding connected components
class Solution {
public:

    int BFS(vector<vector<int>>& grid,vector<vector<int>>& visited,int r,int c,int m,int n){
        queue<pair<int,int>>q;
        q.push({r,c});
        visited[r][c]=1;
        int dr[4]={-1,0,1,0};
        int dc[4]={0,-1,0,1};
        int count=1;
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            int row=top.first;
            int col=top.second;
            for(int i=0;i<4;i++){
            int nrow=dr[i]+row;
            int ncol=dc[i]+col;
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !visited[nrow][ncol] && grid[nrow][ncol]==1){
                q.push({nrow,ncol});
                visited[nrow][ncol]=1;
                count++;
            }
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
                    maxi=max(maxi,BFS(grid,visited,i,j,m,n));
                }
            }
        }
        return maxi;
    }
};

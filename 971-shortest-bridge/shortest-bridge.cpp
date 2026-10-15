class Solution {
public:
    int cnt;
    void dfs(vector<vector<int>>& grid,int r,int c,queue<pair<int,int>>& q) {
        int n=grid.size();
        if(r<0 || r>=n || c<0 || c>=n || grid[r][c]!=1) return;
        grid[r][c]=2;
        q.push({r,c});
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        for(int k=0;k<4;k++) {
            dfs(grid,r+dr[k],c+dc[k],q);
        }
    }
    void bfs(vector<vector<int>>& grid){
        int n=grid.size();
        queue<pair<int,int>> q;
        bool found=false;
        for(int i=0;i<n && !found;i++) {
            for(int j=0;j<n && !found;j++) {
                if(grid[i][j]==1) {
                    dfs(grid,i,j,q);
                    found=true;
                }
            }
        }
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        while (q.size()) {
            int sz=q.size();
            while(sz--) {
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                for(int k=0;k<4;k++) {
                    int nr=row+dr[k];
                    int nc=col+dc[k];
                    if(nr>=0 && nr < n && nc >= 0 && nc < n) {
                        if(grid[nr][nc]==1) return;
                        if(grid[nr][nc]==0) {
                            grid[nr][nc]=2;
                            q.push({nr,nc});
                        }
                    }
                }
            }
            cnt++;
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        cnt=0;
        bfs(grid);
        return cnt;
    }
};
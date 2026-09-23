class Solution {
public:
    void bfs(int sr,int sc,vector<vector<int>>& grid,vector<vector<int>>& ans,int color){
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vector<vector<int>> visit(m,vector<int> (n,0));
        visit[sr][sc]=1;
        int original=grid[sr][sc];
        if(original==color) return;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while(q.size()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            bool isBorder = false;
            for(int k=0;k<4;k++) {
                int nr=row+dr[k];
                int nc=col+dc[k];
                //Outside grid =>  current cell is border
                if(nr<0 || nr>=m || nc<0 || nc>=n) {
                    isBorder=true;
                    continue;
                }
                //Different color => current cell is border
                if(grid[nr][nc]!=original) {
                    isBorder=true;
                    continue;
                }
                //Same color and not visited => BFS
                if(visit[nr][nc]==0) {
                    visit[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
            if(isBorder){
                ans[row][col]=color;
            }
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        vector<vector<int>> ans=grid;
        bfs(row,col,grid,ans,color);
        return ans;
    }
};
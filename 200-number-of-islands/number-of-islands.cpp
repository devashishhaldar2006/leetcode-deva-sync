class Solution {
public:
    void dfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>& visit){
        int m=grid.size();
        int n=grid[0].size();
        if(row>0){
            if(grid[row-1][col]=='1' and visit[row-1][col]==0){
                visit[row-1][col]=1;
                dfs(row-1,col,grid,visit);
            }
        }
        if(row+1<m){
            if(grid[row+1][col]=='1' and visit[row+1][col]==0){
                visit[row+1][col]=1;
                dfs(row+1,col,grid,visit);
            }
        }
        if(col>0){
            if(grid[row][col-1]=='1' and visit[row][col-1]==0){
                visit[row][col-1]=1;
                dfs(row,col-1,grid,visit);
            }
        }
        if(col+1<n){
            if(grid[row][col+1]=='1' and visit[row][col+1]==0){
                visit[row][col+1]=1;
                dfs(row,col+1,grid,visit);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visit(m,vector<int> (n,0));
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' and visit[i][j]==0){
                    dfs(i,j,grid,visit);
                    cnt++;
                }
            }
        }
        return cnt;

    }
};
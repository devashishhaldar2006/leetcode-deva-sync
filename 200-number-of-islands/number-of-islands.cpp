class Solution {
public:
    void bfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& visit){
        int m=grid.size();
        int n=grid[0].size();
        visit[i][j]=1;
        queue<pair<int,int>> q;
        q.push({i,j});
        while(q.size()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            if(row>0){
                if(grid[row-1][col]=='1' and visit[row-1][col]==0){
                    visit[row-1][col]=1;
                    q.push({row-1,col});
                }
            }
            if(row+1<m){
                if(grid[row+1][col]=='1' and visit[row+1][col]==0){
                    visit[row+1][col]=1;
                    q.push({row+1,col});
                }
            }
            if(col>0){
                if(grid[row][col-1]=='1' and visit[row][col-1]==0){
                    visit[row][col-1]=1;
                    q.push({row,col-1});
                }
            }
            if(col+1<n){
                if(grid[row][col+1]=='1' and visit[row][col+1]==0){
                    visit[row][col+1]=1;
                    q.push({row,col+1});
                }
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
                if(grid[i][j]=='1' && visit[i][j]==0){
                    bfs(i,j,grid,visit);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
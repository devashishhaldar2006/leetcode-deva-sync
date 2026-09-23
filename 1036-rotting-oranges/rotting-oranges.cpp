class Solution {
public:
    int count;
    void bfs(vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        while(q.size()){
            int size=q.size();
            while(size--){
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int nr=row+dr[k];
                    int nc=col+dc[k];
                    if(nr>=0 && nc>=0 && nr<m && nc<n){
                        if(grid[nr][nc]==0) continue;
                        if(grid[nr][nc]==1) {
                            grid[nr][nc]=2; 
                            q.push({nr,nc});
                        }
                    }
                }
                
            }
            if(q.size()) count++;
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        count=0;
        bfs(grid);
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return count;
    }
};
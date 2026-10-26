class Solution {
public: 
    int cnt;
    void bfs(vector<vector<int>>& grid,int i,int j,int k,vector<vector<int>>& vis){
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int> > q;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        q.push({i,j});
        vis[i][j]=1;
        long long curr=0;
        while(q.size()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            curr+=grid[row][col];
            for(int k=0;k<4;k++){
                int nr=row+dr[k];
                int nc=col+dc[k];
                if(nr>=0 and nr<m and nc>=0 and nc<n and vis[nr][nc]==0 and grid[nr][nc]>0){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
                
            }
        }
        if(curr%k==0){
            cnt++;
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0 and vis[i][j]==0){
                    bfs(grid,i,j,k,vis);
                }
            }
        }
        return cnt;
    }
};
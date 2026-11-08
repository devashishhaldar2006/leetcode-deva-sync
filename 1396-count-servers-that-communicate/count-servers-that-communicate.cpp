class Solution {
public:
    int cnt;
    void bfs(vector<vector<int>>& grid){
        queue<pair<int,int> > q;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) q.push({i,j});
            }
        }
        while(q.size()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            bool communicates=false;
            //Check entire row
            for(int j=0;j<n;j++) {
                if(j!=col && grid[row][j]==1) {
                    communicates=true;
                    break;
                }
            }
            //Check entire column
            for(int i=0;i<m;i++) {
                if(i!=row && grid[i][col]==1) {
                    communicates=true;
                    break;
                }
            }

            if(communicates && !vis[row][col]) {
                cnt++;
                vis[row][col]=1;
            }
        }

    }
    int countServers(vector<vector<int>>& grid) {
        cnt=0;
        bfs(grid);
        return cnt;
    }
};
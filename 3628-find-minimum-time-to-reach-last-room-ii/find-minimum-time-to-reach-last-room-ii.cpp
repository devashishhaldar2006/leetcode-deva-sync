class Solution {
public:
    typedef pair<int,pair<int,int>> pr;
    int bfs(vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        priority_queue<pr,vector<pr>,greater<pr>> pq;
        pq.push({0,{0,0}});
        vis[0][0]=1;
        while(pq.size()){
            int t=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            if(r==m-1 and c==n-1) return t;
            int moveCost=((r + c) % 2 == 0) ? 1 : 2;
            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];
                if(nr>=0 and nr<m and nc>=0 and nc<n and !vis[nr][nc]){
                    vis[nr][nc]=1;
                    int nt=max(t, grid[nr][nc])+moveCost;
                    pq.push({nt,{nr,nc}});
                }
            }

        }
        return -1;
    }
    int minTimeToReach(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};
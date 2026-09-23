class Solution {
public:
    void bfs(int sr,int sc,vector<vector<int>>& image,vector<vector<int>>& ans,int color){
        int m=image.size();
        int n=image[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vector<vector<int>> visit(m,vector<int> (n,0));
        visit[sr][sc]=1;
        int original=image[sr][sc];
        if(original==color) return;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        ans[sr][sc]=color;
        while(q.size()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nr=row+dr[k];
                int nc=col+dc[k];
                if(nr>=0 && nc>=0 && nr<m && nc<n && visit[nr][nc]==0 && original==image[nr][nc]){
                    ans[nr][nc]=color;
                    visit[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans=image;
        bfs(sr,sc,image,ans,color);
        return ans;
    }
};
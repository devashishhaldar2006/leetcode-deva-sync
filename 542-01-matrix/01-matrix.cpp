class Solution {
public:
    void bfs(vector<vector<int>>& mat,vector<vector<int>>& ans){
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> visit(m,vector<int> (n,0));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    visit[i][j]=1;
                    q.push({i,j});
                }
            }
        }
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        while(q.size()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nr=row+dr[k];
                int nc=col+dc[k];
                if(nr>=0 and nr<m and nc>=0 and nc<n and visit[nr][nc]==0){
                    visit[nr][nc]=1;
                    ans[nr][nc]=ans[row][col]+1; //most important (distance from row,col)
                    q.push({nr,nc});
                }
            }
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> ans=mat;
        bfs(mat,ans);
        return ans;
    }
};
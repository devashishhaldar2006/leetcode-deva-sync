class Solution {
public:
    void bfs(vector<vector<char>>& board){
        int m=board.size();
        int n=board[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    if(i==0 || j==0 || i==m-1 || j==n-1){
                        board[i][j]='#';
                        q.push({i,j});
                    }
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
                if(nr>0 and nr<m-1 and nc>0 and nc<n-1){
                    if(board[nr][nc]=='O'){
                        board[nr][nc]='#';
                        q.push({nr,nc});
                    }
                }
            }
            
        }
        // flip all
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
       bfs(board);
    }
};
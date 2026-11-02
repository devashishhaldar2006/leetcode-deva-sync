class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        int dr[]={-1,-1,-1,0,0,1,1,1};
        int dc[]={-1,0,1,-1,1,-1,0,1};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int curr=0;
                for(int k=0;k<8;k++){
                    int r=i+dr[k];
                    int c=j+dc[k];
                    if(r>=0 and r<m and c>=0 and c<n and (board[r][c]==1 || board[r][c]==2)){
                        curr++;
                    }
                }
                if(board[i][j]==1 and curr<2){
                    board[i][j]=2;
                }
                else if(board[i][j]==1 and (curr==2 || curr==3)){
                    board[i][j]=1;
                }
                else if(board[i][j]==1 and curr>3){
                    board[i][j]=2;
                }
                else if(board[i][j]==0 and curr==3){
                    board[i][j]=3;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                board[i][j]%=2;
            }
        }
    }
};
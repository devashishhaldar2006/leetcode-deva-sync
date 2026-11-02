class Solution {
public:
    void bfs(vector<vector<int>>& matrix){
        int m=matrix.size();
        int n=matrix[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        while(q.size()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int j=0;j<n;j++){
                matrix[row][j]=0;
            }
            for(int i=0;i<m;i++){
                matrix[i][col]=0;
            }
        }

    }
    void setZeroes(vector<vector<int>>& matrix) {
        bfs(matrix);
    }
};
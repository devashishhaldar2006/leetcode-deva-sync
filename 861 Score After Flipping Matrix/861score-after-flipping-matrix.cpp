class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0;i<row;i++){
            if(grid[i][0]==0){
                for(int j=0;j<col;j++){
                    if(grid[i][j]==0) grid[i][j]=1;
                    else grid[i][j]=0;
                }
            }
        }
        for(int i = 1; i < col; i++) {
            int noz = 0, noo = 0;

            for(int j = 0; j < row; j++) {
                if(grid[j][i] == 0) noz++;
                else noo++;
            }

            if(noz > noo) {
                for(int j = 0; j < row; j++) {
                    grid[j][i] ^= 1;
                }
            }
        }
        int sum=0;
        for(int i=0;i<row;i++){
            int x=1;
            for(int j=col-1;j>=0;j--){
                sum+=grid[i][j]*x;
                x*=2;
            }
        }
        return sum;
    }
};
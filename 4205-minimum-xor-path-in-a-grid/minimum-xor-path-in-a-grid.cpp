class Solution {
public:
    void helper(vector<vector<int>>& grid,int i,int j,int x,vector<vector<vector<bool>>>& dp){
       int m=grid.size();
       int n=grid[0].size();
       x^=grid[i][j];
       if(dp[i][j][x]) return;
       dp[i][j][x]=1;
       if(i+1<m){
            helper(grid,i+1,j,x,dp);
       }
       if(j+1<n){
            helper(grid,i,j+1,x,dp);
       }
    }
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<bool>>> dp(
            m, vector<vector<bool>>(n, vector<bool>(1024, false))
        );
        helper(grid,0,0,0,dp);
        for(int x=0;x<1024;x++){
            if(dp[m-1][n-1][x]){
                return x;
            }
        }
        return -1;
    }
};
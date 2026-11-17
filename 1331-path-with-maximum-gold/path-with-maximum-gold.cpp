class Solution {
public:
    int helper(vector<vector<int>>& grid,int r,int c){
        if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || grid[r][c]==0) return 0;

        int gold=grid[r][c];
        grid[r][c]=0;

        int left=helper(grid,r,c-1);
        int right=helper(grid,r,c+1);
        int up=helper(grid,r-1,c);
        int down=helper(grid,r+1,c);

        grid[r][c]=gold;

        return gold + max({left,up,right,down});
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0){
                    ans=max(ans,helper(grid,i,j));
                }
            }
        }
        return ans;
    }
};
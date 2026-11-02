class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> arr;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                arr.push_back(grid[i][j]);
            }
        }
        sort(arr.begin(),arr.end());
        int sz=arr.size();
        int md=arr[sz/2];
        int cnt=0;
        for(int i=0;i<sz;i++) {
            if(abs(arr[i]-md)%x!=0) return -1;
            cnt+=abs(arr[i]-md)/x;
        }

        return cnt;
    }
};
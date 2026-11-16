class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int cnt=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                vector<int> colSum(n,0);
                for(int k=i;k<m;k++) {
                    int rectSum=0;
                    for(int l=j;l<n;l++) {
                        colSum[l]+=matrix[k][l]; 
                        rectSum+=colSum[l];
                        if(rectSum==target) {
                            cnt++;
                        }
                    }
                }
            }
        }
        return cnt;
    }
};
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> ans;
        int minr = 0, maxr = row - 1;
        int minc = 0, maxc = col - 1;

        while (minr <= maxr && minc <= maxc) {
            // top row
            for (int i = minc; i <= maxc; i++) {
                ans.push_back(matrix[minr][i]);
            }
            minr++;
            // right column
            for (int i = minr; i <= maxr; i++) {
                ans.push_back(matrix[i][maxc]);
            }
            maxc--;
            // bottom row
            if (minr <= maxr) {
                for (int i = maxc; i >= minc; i--) {
                    ans.push_back(matrix[maxr][i]);
                }
                maxr--;
            }
            // left column
            if (minc <= maxc) {
                for (int i = maxr; i >= minr; i--) {
                    ans.push_back(matrix[i][minc]);
                }
                minc++;
            }
        }

        return ans;
    }
};
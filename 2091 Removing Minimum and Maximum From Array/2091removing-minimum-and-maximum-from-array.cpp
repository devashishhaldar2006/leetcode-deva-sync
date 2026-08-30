class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mxIdx = -1;
        int mnIdx = -1;
        int mx = INT_MIN;
        int mn = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (nums[i] > mx) {
                mx = nums[i];
                mxIdx = i;
            }
            if (nums[i] < mn) {
                mn = nums[i];
                mnIdx = i;
            }
        }
        int left = min(mxIdx, mnIdx);
        int right = max(mxIdx, mnIdx);
        int option1 = right + 1;
        int option2 = n - left;
        int option3 = left + 1 + n - right;
        return min({option1, option2, option3});
    }
};
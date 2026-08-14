class Solution {
public:
    int maxSum;
    int solve(int idx, vector<int>& nums, vector<int>& dp) {
        if(idx==0) return dp[idx]=nums[idx];
        if(dp[idx]!=-1) return dp[idx];
        return dp[idx]=max(nums[idx],solve(idx-1,nums,dp)+nums[idx]);
    }
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        maxSum=INT_MIN;
        for(int i=0;i<n;i++) {
            maxSum=max(maxSum,solve(i,nums,dp));
        }
        return maxSum;
    }
};
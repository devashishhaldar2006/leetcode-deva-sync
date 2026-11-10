class Solution {
public:
    int helper(vector<int>& nums,vector<vector<int>>& dp,int i,int j) {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mx=0;
        for(int k=i;k<=j;k++) {
            int coins=nums[i-1]*nums[k]*nums[j+1];
            coins+=helper(nums,dp, i, k-1);
            coins+=helper(nums,dp, k+1, j);
            mx=max(mx,coins);
        }
        return dp[i][j]=mx;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n+2,vector<int> (n+2,-1));
        return helper(nums,dp,1,n);
    }
};
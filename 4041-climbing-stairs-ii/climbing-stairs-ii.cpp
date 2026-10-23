class Solution {
public:
    int helper(vector<int>& cost,int i,vector<int>& dp){
        if(i==0) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=INT_MAX;
        if(i-1>=0){
            ans=min(ans,cost[i-1]+1+helper(cost,i-1,dp));
        }
        if(i-2>=0){
            ans=min(ans,cost[i-1]+4+helper(cost,i-2,dp));
        }
        if(i-3>=0){
            ans=min(ans,cost[i-1]+9+helper(cost,i-3,dp));
        }
        return dp[i]=ans;
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1,-1);
        return helper(costs,n,dp);
    }
};
class Solution {
public:
    int helper(vector<int>& prices,int& sum,int i,vector<int>& dp){
        int n=prices.size();
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        if(i+1<n and prices[i+1]>prices[i]) {
            int profit=prices[i+1]-prices[i];
            return dp[i]=profit+helper(prices,sum,i+1,dp);
        }
        return dp[i]=helper(prices,sum,i+1,dp);
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int sum=0;
        vector<int> dp(n+1,-1);
        return helper(prices,sum,0,dp);
    }
};
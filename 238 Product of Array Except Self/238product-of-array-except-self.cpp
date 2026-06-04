class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n);
        pre[0]=1;
        int prod=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=prod;
            prod*=nums[i];
        };
        prod=nums[n-1];
        for(int i=n-2;i>=0;i--){
            pre[i]=pre[i]*prod;
            prod*=nums[i];
        }
        return pre;
    }
};
class Solution {
public:
    int helper(vector<int>& nums,int i,int curr){
        int n=nums.size();
        if(i==n) return curr;
        int take=helper(nums,i+1,nums[i]^curr);
        int leave=helper(nums,i+1,curr);
        return take + leave;
    }
    int subsetXORSum(vector<int>& nums) {
        return helper(nums,0,0);
    }
};
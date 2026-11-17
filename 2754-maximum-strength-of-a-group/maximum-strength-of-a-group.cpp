class Solution {
public:
    long long helper(vector<int>& nums,int i,long long ans,bool taken){
        int n=nums.size();
        if(i==n){
            return taken ? ans : LLONG_MIN;
        }
        long long take=helper(nums,i+1,ans*nums[i],true);
        long long leave=helper(nums,i+1,ans,taken);
        return max(take,leave);
    }
    long long maxStrength(vector<int>& nums) {
        int n=nums.size();
        return helper(nums,0,1,false);
    }
};
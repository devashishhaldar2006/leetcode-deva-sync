class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            count+=min(nums[i]%3,3-(nums[i]%3));
        }
        return count;
    }
};
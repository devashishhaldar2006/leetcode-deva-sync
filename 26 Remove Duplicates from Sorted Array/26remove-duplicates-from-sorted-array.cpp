class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int start=1;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[start-1]){
                nums[start]=nums[i];
                start++;
            }
        }
        return start;
    }
};
class Solution {
public:
    bool binarySearch(vector<int>& nums,int target){
        int n=nums.size();
        int lo=0,hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target){
                return true;
            }
            else if(nums[mid]>target){
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return false;
    }
    int findFinalValue(vector<int>& nums, int original) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        while(binarySearch(nums,original)){
            original=2*original;
        }
        return original;
    }
};
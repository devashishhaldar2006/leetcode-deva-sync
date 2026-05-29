class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lo=0;
        int hi=nums.size()-1;
        vector<int> res;
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target){
                ans=mid;
                hi=mid-1;
            }
            else if(nums[mid]<target) lo=mid+1;
            else hi=mid-1;
        }
        res.push_back(ans);
        ans=-1;
        lo=0,hi=nums.size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target){
                ans=mid;
                lo=mid+1;
            }
            else if(nums[mid]<target) lo=mid+1;
            else hi=mid-1;
        }
        res.push_back(ans);
        return res;
    }
};
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        int minSum=INT_MAX;
        for(int i=0;i<n;i++){
            int curr=0;
            int len=0;
            for(int j=i;j<n;j++){
                curr+=nums[j];
                len++;
                if(len>=l and len<=r){
                    if(curr>0) minSum=min(minSum,curr);
                }
            }
        }
        if(minSum==INT_MAX) return -1;
        return minSum;
    }
};
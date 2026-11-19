class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        // 1 4 5 7 8
        int cntA=nums[n-3]-nums[0];
        int cntB=nums[n-2]-nums[1];
        int cntC=nums[n-1]-nums[2];
        return min({cntA,cntB,cntC});

    }
};
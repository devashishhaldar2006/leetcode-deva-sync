class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        int mid=INT_MAX;
        sort(nums.begin(),nums.end());
        if(n%2==0) mid=(nums[n/2]+nums[n/2-1])/2;
        else mid=nums[n/2];
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=abs(nums[i]-mid);
        }
        return cnt;
    }
};
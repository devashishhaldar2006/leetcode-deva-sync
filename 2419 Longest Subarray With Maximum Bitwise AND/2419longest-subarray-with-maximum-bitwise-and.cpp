class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        int count=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==mx){
                count++;
                ans=max(count,ans);
            }
            else {
                count=0;
            }
        }
        return ans;
    }
};
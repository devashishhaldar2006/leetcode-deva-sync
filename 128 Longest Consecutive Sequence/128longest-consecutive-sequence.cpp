class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(nums.empty()){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int maxlen=1;
        int currlen=1;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                currlen++;
            }
            else if(nums[i]!=nums[i-1]){
                currlen=1;
            }
            maxlen=max(maxlen,currlen);
        }
        return maxlen;
    }
};
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=0;
        int maxLen=INT_MIN;
        int len=INT_MIN;
        int flips=0;
        int k=1;
        while(j<n){
            if(nums[j]==1) j++;
            else{
                if(flips<k){ 
                    flips++;
                    j++;
                }
                else{
                    len=j-i;
                    maxLen=max(len,maxLen);
                    while(nums[i]==1) i++;
                    i++;
                    j++;
                }
            }          
        }
        len=j-i;
        maxLen=max(len,maxLen);
        return maxLen-1;
    }
};
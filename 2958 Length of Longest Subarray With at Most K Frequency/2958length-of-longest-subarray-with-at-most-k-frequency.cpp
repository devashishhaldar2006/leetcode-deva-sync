class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int maxLen=0;
        while(i<n){
            int j=i;
            int len=0;
            unordered_map<int,int> m;
            while(j<n){
                m[nums[j]]++;
                while(m[nums[j]]>k){
                    m[nums[i]]--;
                    i++;
                }
                len=j-i+1;
                if(m[nums[j]]<=k){
                    maxLen=max(len,maxLen);
                }
                j++;
            }
            i=j;
        }
        return maxLen;
    }
};
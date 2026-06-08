class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int n=nums.size();
        int i=0;
        int j=0;
        int count=0;
        int prod=1;
        while(j<n){
            prod*=nums[j];
            while(prod>=k){
                count+=(j-i);
                prod/=nums[i];
                i++;
            }
            j++;
        }
        while(i<n){
            count+=(j-i);
            prod/=nums[i];
            i++;
        }
        return count;
    }
};
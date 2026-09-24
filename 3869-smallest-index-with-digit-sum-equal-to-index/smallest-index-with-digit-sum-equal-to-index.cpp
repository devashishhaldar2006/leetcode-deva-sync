class Solution {
public:
    int sum(int n){
        int res=0;
        while(n){
            res+=n%10;
            n/=10;
        }
        return res;
    }
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i==sum(nums[i])) return i;
        }
        return -1;
    }
};
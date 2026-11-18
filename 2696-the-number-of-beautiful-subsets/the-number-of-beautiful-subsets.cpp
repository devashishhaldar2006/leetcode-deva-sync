class Solution {
public:
    int helper(vector<int>& nums, int k,int i,vector<int>& freq){
        int n=nums.size();
        if(i==n){
            return 1;
        }
        int cnt=helper(nums,k,i+1,freq);

        if(nums[i]-k<0 || freq[nums[i]-k]==0){
            freq[nums[i]]++;
            cnt+=helper(nums,k,i+1,freq);
            freq[nums[i]]--;
        }
        return cnt;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<int> freq(1001,0);
        return helper(nums,k,0,freq)-1;
    }
};
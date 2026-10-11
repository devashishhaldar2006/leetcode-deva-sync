class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr;
        for(int i=0;i<n;i++){
            if(n%(i+1)==0) arr.push_back(nums[i]);
        }
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i]*arr[i];
        }
        return sum;
    }
};
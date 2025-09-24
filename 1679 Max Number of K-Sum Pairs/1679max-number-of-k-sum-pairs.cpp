class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int operations=0;
        int i=0;
        int j=n-1;
         while (i<j) {
            int sum=nums[i] + nums[j];
            if (sum == k) {
                operations++;
                i++;
                j--;
            }
            else if(sum<k) {
                i++; 
            }
            else {
                j--;
            }
        }
        return operations;
    }
};
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr;
        vector<int> drr;
        arr.push_back(nums[0]);
        drr.push_back(nums[1]);
        int i=2,j=0,k=0;
        while(i<n){
            if(arr[j]>drr[k]){
                arr.push_back(nums[i]);
                j++;
            }
            else{
                drr.push_back(nums[i]);
                k++;
            }
            i++;
        }
        int m=0;
        while(m<drr.size()){
            arr.push_back(drr[m]);
            m++;
        }
        return arr;
    }
};
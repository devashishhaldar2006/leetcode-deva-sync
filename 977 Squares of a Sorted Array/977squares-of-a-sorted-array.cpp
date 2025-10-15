class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=n-1;
        vector<int> result(n);
        int pos=n-1;
        while (i<=j) {
            int leftSquare=nums[i]*nums[i];
            int rightSquare=nums[j]*nums[j];
            if(leftSquare>rightSquare) {
                result[pos]=leftSquare;
                i++;                      
            } else{
                result[pos]=rightSquare; 
                j--;                       
            }
            pos--; 
        }
        return result;
    }
};

class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> m;
        int mxFreq=0;
        for(auto num:nums){
            m[num]++;
            if(m[num]>mxFreq){
                mxFreq=m[num];
            }
        }
        if(mxFreq>n/2){
            return 2*mxFreq-n;
        }
        return n%2;
    }
};
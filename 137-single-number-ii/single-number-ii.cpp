class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> m;
        for(auto ele:nums){
            m[ele]++;
        }
        for(auto itr:m){
            if(itr.second==1) return itr.first;
        }
        return -1;
    }
};
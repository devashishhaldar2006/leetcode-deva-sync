class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            int rem=target-nums[i];
            if(m.find(rem)!=m.end()){
                return {m[rem],i};
            }
            else m[nums[i]]=i;
        }
        return {};
    }   
};
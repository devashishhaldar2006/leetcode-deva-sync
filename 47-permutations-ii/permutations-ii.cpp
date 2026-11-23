class Solution {
public:
    void helper(vector<int>& nums,int idx,vector<vector<int>>& ans){
        if(idx==nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> s;
        for(int i=idx;i<nums.size();i++){
            if(s.count(nums[i])) continue;
            s.insert(nums[i]);
            swap(nums[idx],nums[i]);
            helper(nums,idx+1,ans);
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        helper(nums,0,ans);
        return ans; 
    }
};
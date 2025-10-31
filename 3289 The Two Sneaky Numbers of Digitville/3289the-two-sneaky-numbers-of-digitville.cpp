class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map <int,int> m;
        for(auto ele:nums){
            m[ele]++;
        }
        vector<int> ans;
        for(auto itr:m){
            int x=itr.second;
            if(x==2) ans.push_back(itr.first);
        }
        return ans;
    }
};
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> m;
        for(auto num:nums) m[num]++;
        int temp=k;
        while(k<101){
            if(m.find(k)==m.end()) return k;
            k+=temp;
        }
        return k;
    }
};
class Solution {
public:
    bool uniqueOccurrences(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto num:nums){
            m[num]++;
        }
        unordered_set<int> s;
        for(auto itr:m){
            int x=itr.second;
            if(s.find(x)!=s.end()){
                return false;
            }
            else s.insert(x);
        }
        return true;
    }
};
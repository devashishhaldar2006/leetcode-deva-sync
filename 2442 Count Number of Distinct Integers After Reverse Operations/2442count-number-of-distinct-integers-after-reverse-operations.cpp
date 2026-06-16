class Solution {
public:
    int rev(int n){
        int ans=0;
        while(n){
            ans=ans*10+(n%10);
            n/=10;
        }
        return ans;
    }
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s;
        int n=nums.size();
        for(auto num:nums){
            s.insert(num);
            s.insert(rev(num));
        }
        return s.size();
    }
};
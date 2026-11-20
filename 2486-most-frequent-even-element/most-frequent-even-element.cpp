class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> m;
        for(auto num: nums) m[num]++;
        int mx=0;
        int ele=-1;
        for(auto itr:m){
            if(itr.first%2==0){
                if(itr.second>mx) {
                    mx=itr.second;
                    ele=itr.first;
                }
                else if(itr.second==mx){
                    ele=min(ele,itr.first);
                }
            }
        }
        return ele;

    }
};
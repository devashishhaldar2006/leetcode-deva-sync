class Solution {
public:
    int majorityElement(vector<int>& arr) {
        unordered_map<int,int> map;
        int n=arr.size();
        for(int i=0;i<n;i++) map[arr[i]]++;
        for(auto i:map) {
            if(i.second>n/2) {
                return i.first;
            }
        }
        return -1;
    }
};
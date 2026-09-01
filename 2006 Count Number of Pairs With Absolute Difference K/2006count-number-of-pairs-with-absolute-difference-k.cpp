class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++) m[nums[i]]++;
        int cnt=0;
        // k=2
        // [3,2,1,5,4]
        // 4 
        // expect 3

        for(int i=0;i<n;i++){
            int target=nums[i]+k;
            if(m.find(target)!=m.end()) cnt+=m[target];
        }
        return cnt;
        
    }
};
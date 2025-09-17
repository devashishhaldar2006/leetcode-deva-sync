class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> pre(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        unordered_map<int, int> freq;
        freq[0]=1;
        int count=0;
        for(int i=0;i<n;i++) {
            int mod=((pre[i]%k)+k)%k;
            if(freq.find(mod)!=freq.end()) {
                count+=freq[mod];
            }
            freq[mod]++;
        }
        return count;
    }
};
class Solution {
public:
    int binary_to_decimal(string &binary){
        int n=binary.size();
        int mod=0;
        for(int i = 0; i < n; i++){
            int num = binary[i] - '0';
            mod = ( (mod << 1) + num ) % 5;
        }
        return mod;
    }
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n=nums.size();
        vector<string> pre(n);
        pre[0]=to_string(nums[0]);
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+to_string(nums[i]);
        }
        vector<bool> ans;
        for(int i=0;i<n;i++){
            if((binary_to_decimal(pre[i]))%5==0){
                ans.push_back(true);
            }
            else ans.push_back(false);
        }
        return ans;
    }
};
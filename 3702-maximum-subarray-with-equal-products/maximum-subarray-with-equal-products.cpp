class Solution {
public:
    typedef long long ll;
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int maxLen=0;
        for(int i=0;i<n;i++){
            int len=0;
            ll curr=1;
            int g=nums[i];
            int l=nums[i];
            for(int j=i;j<n;j++){
                curr*=(ll)nums[j];
                g=gcd(g,nums[j]);
                l=lcm(l,nums[j]);
                len++;
                if((ll)curr==(ll)l*g){
                    maxLen=max(maxLen,len);
                }
                if (curr > 25200) break;
            }
           
        }
        return maxLen;
    }
};
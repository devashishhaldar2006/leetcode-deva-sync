class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> mx(n,0);
        vector<int> mn(n,0);
        int a=INT_MIN;;
        for(int i=0;i<n;i++){
            a=max(a,nums[i]);
            mx[i]=a;
        }
        int b=INT_MAX;;
        for(int i=n-1;i>=0;i--){
            b=min(b,nums[i]);
            mn[i]=b;
        }
        for(int i=0;i<n;i++){
            mx[i]=mx[i]-mn[i];
        }
        for(int i=0;i<n;i++){
            if(mx[i]<=k) return i;
        }
        return -1;
    }
};
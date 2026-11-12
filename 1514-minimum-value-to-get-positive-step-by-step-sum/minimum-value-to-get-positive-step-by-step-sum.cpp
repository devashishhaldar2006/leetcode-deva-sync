class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n=nums.size();
        // [-3,2,-3,4,2]
        int start=1;
        while(true){
            vector<int> pre(n);
            pre[0]=start+nums[0];
            for(int i=1;i<n;i++){
                pre[i]=pre[i-1]+nums[i];
            }
            bool flag=true;
            for(int i=0;i<n;i++){
                if(pre[i]<=0) {
                    flag=false;
                    break;
                }
            }
            if(flag) return start;
            start++;
        }
    }
};
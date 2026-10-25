class Solution {
public:
    int count(int n){
        int cnt=0;
        while(n){
            cnt++;
            n/=10;
        }
        return cnt;
    }
    bool canAliceWin(vector<int>& nums) {
        int n=nums.size();
        int s1=0;
        int s2=0;
        int total=accumulate(nums.begin(),nums.end(),0);
        int temp=total;
        for(int i=0;i<n;i++){
            if(count(nums[i])==1){
                s1+=nums[i];
                total-=nums[i];
            }
            else{
                s2+=nums[i];
                temp-=nums[i];
            }
        }
        if(s1>total || s2>temp){
            return true;
        }
        return false;
    }
};
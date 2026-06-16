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
    int countNicePairs(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        unordered_map<int,int> m;
        for(auto &num:nums){
            num-=rev(num);
        }
        for(auto num:nums){
            if(m.find(num)!=m.end()){
                cnt=cnt%1000000007;
                cnt+=m[num];
            }
            m[num]++;
        }
        return cnt%1000000007;
    }
};
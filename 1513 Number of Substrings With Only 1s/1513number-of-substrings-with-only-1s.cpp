class Solution {
public:
    int numSub(string s) {
        const int MOD=pow(10,9) + 7;
        long long ans=0;
        long long count=0;
        for(char c : s) {
            if(c == '1') {
                count++;
            } 
            else {
                ans += (count * (count + 1)) / 2;
                ans %= MOD;
                count = 0;
            }
        }
        ans += (count * (count + 1)) / 2;
        ans %= MOD;
        return (int)ans;
    }
};

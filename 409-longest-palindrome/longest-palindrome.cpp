class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int,int> m;
        for(auto ch:s){
            m[ch]++;
        }
        int ans=0;
        int odd=0;
        bool flag=true;
        for(auto x:m){
            if(x.second%2==0){
                ans+=x.second;
            }
            else{
                odd+=x.second-1;
                flag=false;
            }
        }
        if(flag) return ans+odd;
        return ans+odd+1;
    }
};
class Solution {
public:
    int reverseDegree(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            char ch=s[i];
            int num=122-(int)ch+1;
            ans+=(num*(i+1));
        }
        return ans;
    }
};
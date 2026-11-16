class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size() > k) {
            string curr="";
            int sum=0;
            for(int i=0;i<s.size();i++) {
                sum+=s[i]-'0';
                if((i+1)%k==0 || i==s.size()-1) {
                    curr+=to_string(sum);
                    sum=0;
                }
            }
            s=curr;
        }
        return s;
    }
};
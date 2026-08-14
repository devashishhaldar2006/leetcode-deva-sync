class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int j=0;
        while(j<n && s[j]==' ') j++;
        bool negative=false;
        if(j<n&& (s[j]=='+' || s[j]=='-')){
            if(s[j]=='-') negative=true;
            j++;
        }
        long long ans=0;
        while(j<n&& isdigit(s[j])) {
            int digit=s[j]-'0';
            ans=ans*10+digit;
            if(!negative && ans>INT_MAX) return INT_MAX;
            if(negative && -ans<INT_MIN) return INT_MIN;
            j++;
        }

        return negative?-ans:ans;
    }
};
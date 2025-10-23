class Solution {
public:
    bool hasSameDigits(string str) {
        while(str.size()>2) {
            string temp="";
            for(int i=1;i<str.size();i++) {
                int a=str[i]-'0';
                int b=str[i-1]-'0';
                int rem=(a+b)%10;
                temp+=(rem+'0');
            }
            str = temp;
        }
        return str[0] == str[1];
    }
};

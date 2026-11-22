class Solution {
public:
    bool checkString(string s) {
        bool flag=false;
        for(auto ch:s){
            if(flag and ch=='a') return false;
            else if(ch=='b'){
                flag=true;
            }
        }
        return true;
    }
};
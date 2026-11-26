class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10) return false;
        int curr=10;
        bool flag=true;
        while(n>=curr){
            n=n-curr;
            curr--;
            flag=!flag;
        }
        return !flag;
    }
};
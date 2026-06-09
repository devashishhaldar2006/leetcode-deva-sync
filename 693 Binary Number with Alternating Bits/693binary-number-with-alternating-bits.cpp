class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev=n%2;
        n=n/2;
        while(n>0){
            int curr=n%2;
            if(prev==curr) return false;
            prev=curr;
            n/=2;
        }
        return true;
    }
};
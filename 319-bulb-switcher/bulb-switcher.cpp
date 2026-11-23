class Solution {
public:
    int helper(int n){
        if(sqrt(n)*sqrt(n)==n) return true;
        return false;
    }
    int bulbSwitch(int n) {
        return floor(sqrt(n));
    }
};
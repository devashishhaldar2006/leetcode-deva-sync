class Solution {
public:
    int count(int n){
        return __builtin_popcount(n);
    }
    int calculateScore(int a, int b) {
        int s1=count(a);
        int s2=count(b);
        if(s1>=s2){
            return s1*s2;
        }
        else{
            return s2/s1;
        }
    }
};
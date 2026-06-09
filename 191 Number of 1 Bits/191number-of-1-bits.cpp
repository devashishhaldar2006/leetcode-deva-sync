class Solution {
public:
    int setBits(int n){
        return __builtin_popcount(n);
    }
    int hammingWeight(int n) {
        return setBits(n);
    }
};
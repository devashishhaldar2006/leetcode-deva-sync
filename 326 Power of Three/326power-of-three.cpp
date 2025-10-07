class Solution {
public:
    bool isPowerOfThree(int n) {
        const int maxPowerOf3 = 1162261467; // 3^19
        return (n > 0) && (maxPowerOf3 % n == 0);
    }
};
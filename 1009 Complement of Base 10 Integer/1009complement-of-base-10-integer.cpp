class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        int mask = 0;
        int k = n;

        while(k > 0) {
            mask = (mask << 1) | 1;
            k >>= 1;
        }

        return mask ^ n;
    }
};
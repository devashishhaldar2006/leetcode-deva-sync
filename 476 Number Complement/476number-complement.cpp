class Solution {
public:
    int findComplement(int num) {
        if(num == 0) return 1;
        int k=num;
        int mask=0;
        while(k){
            mask=(mask<<1) | 1;
            k >>=1;
        }
        return (num^mask);
    }
};
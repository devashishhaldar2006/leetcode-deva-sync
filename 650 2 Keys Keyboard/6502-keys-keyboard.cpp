class Solution {
public:

    int highestFactor(int n){
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0){
                return n/i;
            }
        }
        return 1;
    }
    int minSteps(int n) {
        int count=0;
        while(n>1){
            int val=highestFactor(n);
            count+=(n/val);
            n=val;
        }
        return count;
    }
};
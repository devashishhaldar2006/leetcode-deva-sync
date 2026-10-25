class Solution {
public:
    vector<int> evenOddBit(int n) {
        int cntA=0;
        int cntB=0;
        int curr=0;
        while(n){
            if(n%2==1){
                if(curr%2==0){
                    cntA++;
                }
                else{
                    cntB++;
                }
                
            }
            curr++;
            n=n/2;
        }
        return {cntA,cntB};
    }
};
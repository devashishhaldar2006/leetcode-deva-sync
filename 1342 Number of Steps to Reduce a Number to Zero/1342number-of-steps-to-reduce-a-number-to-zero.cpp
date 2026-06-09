class Solution {
public:
    int numberOfSteps(int num) {
        if(!num) return 0;
        int count=0;
        while(num){
            if((num %2) == 0) count++;
            else{
                count+=2;
            }
            num>>=1;
        }
        return count-1;
    }
};
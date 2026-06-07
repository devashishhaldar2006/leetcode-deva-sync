class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num==1) return false;
        int sum=0;
        for(int i=2;i<=sqrt(num);i++){
            if(num%i==0){
                sum+=i;
                if(i!=sqrt(num)) sum+=num/i;
            }
        }
        return sum+1==num;
    }
};
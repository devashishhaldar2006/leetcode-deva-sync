class Solution {
public:
    int sumOfDigits(int n){
        int ans=0;
        while(n){
            ans+=n%10;
            n/=10;
        }
        return ans;
    }
    int productOfDigits(int n){
        int ans=1;
        while(n){
            ans*=n%10;
            n/=10;
        }
        return ans;
    }
    bool checkDivisibility(int n) {
        return (n%(sumOfDigits(n)+productOfDigits(n))==0);
    }
};
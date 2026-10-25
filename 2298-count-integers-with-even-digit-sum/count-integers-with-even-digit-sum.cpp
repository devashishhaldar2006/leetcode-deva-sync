class Solution {
public:
    int sum(int n){
        int sum=0;
        while(n){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int countEven(int num) {
        int cnt=0;
        for(int i=1;i<=num;i++){
            int curr=sum(i);
            if(curr%2==0 and curr<=num) cnt++;
        }
        return cnt;
    }
};
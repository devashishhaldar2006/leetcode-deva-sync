class Solution {
public:
    bool isPerfect(int n){
        int root=sqrt(n);
        return root*root==n;
    }
    bool judgeSquareSum(int c) {
        int x=0;
        int y=c;
        while(x<=y){
            if(isPerfect(x) && isPerfect(y)){
                return true;
            }
            else if(!isPerfect(y)){
                y=((int)sqrt(y)*(int)sqrt(y));
                x=c-y;
            }
            else{
                x=((int)(sqrt(x)+1)*(int)(sqrt(x)+1));
                y=c-x;
            }
        }
        return false;
    }
};
class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        long long cnt=0;
        if(maxDoubles==0){
            return target-1;
        }
        while((long long)target!=1){
            if((long long)target%2!=0 || !maxDoubles){
                target--;
                (long long)cnt++;
            }
            else{
                if(maxDoubles){
                    target=(long long)target/2;
                    (long long)cnt++;
                    maxDoubles--;
                }
            }
        }
        return (int)cnt;
    }
};
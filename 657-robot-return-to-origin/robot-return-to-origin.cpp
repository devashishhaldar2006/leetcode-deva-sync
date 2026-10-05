class Solution {
public:
    bool judgeCircle(string moves) {
        int l=0;
        int r=0;
        int u=0;
        int d=0;
        for(auto ch:moves){
            if(ch=='L'){
                l++;
            }
            else if(ch=='R'){
                r++;
            }
            else if(ch=='U'){
                u++;
            }
            else{
                d++;
            }
        }
        if(l==r and u==d){
            return true;
        }
        return false;
    }
};
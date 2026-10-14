class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num) return "";
        string ans="";
        for(int i=0;i<num;i++){
            int digit=min(9,sum);
            ans+=(digit+'0');
            sum-=digit;
        }
        return ans;
    }
};
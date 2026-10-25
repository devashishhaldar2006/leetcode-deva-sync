class Solution {
public:
    int sq(int n){
        int sum=0;
        while(n){
            int rem=n%10;
            sum+=(pow(rem,2));
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> st;
        while(n!=1){
            if(st.count(n)){
                return false;
            }
            st.insert(n);
            n=sq(n);
        }
        return true;

    }
};
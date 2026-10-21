class Solution {
public:
    int minOperations(string s) {
    // already sorted -> return 0
    // length is 2 -> return -1
    // (smallest character is at first) or (largest character is at last) -> return 1
    // (one and only largest character at first) and (one and only smallest character at last) -> return 3
    // fallback -> return 2
        int n=s.size();
        if(is_sorted(s.begin(),s.end())) return 0;
        if(n==2) return -1;
        char mx=*max_element(s.begin(),s.end());
        char mn=*min_element(s.begin(),s.end());
        if(s[0]==mn || s[n-1]==mx){
            return 1;
        }
        if(s[0]==mx and s[n-1]==mn and count(s.begin(), s.end(), mx) == 1 &&
count(s.begin(), s.end(), mn) == 1){
            return 3;
        }
        return 2;
    }
};
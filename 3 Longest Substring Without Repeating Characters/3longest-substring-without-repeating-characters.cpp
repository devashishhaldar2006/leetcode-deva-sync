class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int i=0;
        int j=0;
        int mxLen=0;
        unordered_set<char> st;
        while(j<n) {
            while(st.count(s[j])) {
                st.erase(s[i]);
                i++;
            }
            st.insert(s[j]);
            j++;
            int len=j-i;
            mxLen=max(mxLen, len);
        }
        return mxLen;
    }
};

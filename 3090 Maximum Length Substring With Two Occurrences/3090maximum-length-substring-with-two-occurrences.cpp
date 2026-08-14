class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        int i=0;
        int maxLen=0;
        int k=2;
        while(i<n){
            int j=i;
            int len=0;
            unordered_map<char,int> m;
            while(j<n){
                m[s[j]]++;
                while(m[s[j]]>k){
                    m[s[i]]--;
                    i++;
                }
                len=j-i+1;
                if(m[s[j]]<=k){
                    maxLen=max(len,maxLen);
                }
                j++;
            }
            i=j;
        }
        return maxLen;
    }
};
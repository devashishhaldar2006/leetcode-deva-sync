class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> m;
        int n=s.size();
        int i=0;
        int j=0;
        int ans=0;
        while(j<n) {
            m[s[j]]++;
            while(m['a']>0 && m['b']>0&&m['c']>0) {
                ans+=(n-j);
                m[s[i]]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};
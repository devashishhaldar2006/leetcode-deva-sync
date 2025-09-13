class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        int mx=0;
        int mx2=0;
        for(auto it:m){
            if (it.first == 'a' || it.first == 'e' || it.first == 'i' || it.first == 'o' || it.first == 'u') {
            mx=max(it.second,mx);
        }
        else{
            mx2=max(it.second,mx2);
        }

        }
        return mx+mx2;
    }
};
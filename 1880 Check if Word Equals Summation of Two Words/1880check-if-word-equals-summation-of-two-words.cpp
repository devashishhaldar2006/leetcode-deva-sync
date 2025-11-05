class Solution {
public:
    int convert(string s){
        int i=0;
        int ans=0;
        while(i<s.size()){
            int t=s[i]-'a';
            ans=ans*10+(t);
            i++;
        }
        return ans;
    }
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int f=convert(firstWord);
        int s=convert(secondWord);
        int t=convert(targetWord);
        return f+s==t;
    }
};
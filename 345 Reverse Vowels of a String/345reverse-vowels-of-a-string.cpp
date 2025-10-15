class Solution {
public:
    bool isVowel(char c) {
    //Check vowels directly
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}
    string reverseVowels(string s) {
        int n=s.size();
        int i=0;
        int j=n-1;
        while(i<j){
            while((i<j) && !isVowel(s[i])) i++;
            while((i<j) && !isVowel(s[j])) j--;
            if(i<j) {
                // Swap vowels
                swap(s[i],s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};
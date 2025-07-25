class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size() <= 0) {
            return 0;
        }
        stringstream str(s);
        string word;
        while(str>>word);
        return word.size();
    }
};
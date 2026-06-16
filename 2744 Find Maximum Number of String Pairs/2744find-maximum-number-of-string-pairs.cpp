class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int cnt=0;
        unordered_set<string> s;
        for(auto word:words){
            string rev=word;
            reverse(rev.begin(),rev.end());
            if(s.find(rev)!=s.end()){
                cnt++;
            }
            else s.insert(word);
        }
        return cnt;
    }
};
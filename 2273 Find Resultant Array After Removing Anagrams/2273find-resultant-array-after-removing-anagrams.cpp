class Solution {
public:
    bool anagram(string a,string b){
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        if(a==b) return true;
        else return false;
    }
    vector<string> removeAnagrams(vector<string>& v) {
        vector<string> ans;
        if(v.empty()) return ans;
        ans.push_back(v[0]);
        for(int i=1;i<v.size();i++){
            if(!anagram(v[i],ans.back())){
                ans.push_back(v[i]);
            }
        }
        return ans;
    }
};
class Solution {
public:
    void fill(vector<string>& ans,string s,int op,int cp,int n){
        if(cp==n){
            ans.push_back(s);
            return;
        }
        if(op<n) fill(ans,s+'(',op+1,cp,n);
        if(cp<op) fill(ans,s+')',op,cp+1,n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        fill(ans,"",0,0,n);
        return ans;
    }
};
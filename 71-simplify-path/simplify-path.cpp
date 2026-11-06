class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string temp="";
        vector<string> v;
        for(auto ch:path){
            if(ch=='/'){
                v.push_back(temp);
                temp="";
                continue;
            }
            temp+=ch;
        }
        v.push_back(temp);
        for(auto ele:v){
           if(ele=="." || ele=="") continue;
           else if(ele==".."){
            if(s.size()) s.pop();
           }
           else s.push(ele);
        }
        string res="";
        v.clear();
        while(s.size()){
            v.push_back(s.top());
            s.pop();
        }
        while(v.size()){
            res+="/"+v.back();
            v.pop_back();
        }
        return !res.size() ? "/" : res;
        
    }
};
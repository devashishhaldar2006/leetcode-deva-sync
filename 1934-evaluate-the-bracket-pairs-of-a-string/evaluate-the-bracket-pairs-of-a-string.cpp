class Solution {
public:
    string evaluate(string s, vector<vector<string>>& arr) {
        unordered_map<string,string> m;
        for(int i=0;i<arr.size();i++){
            string key=arr[i][0];
            string val=arr[i][1];
            m[key]=val;
        }
        m[""]="";
        string ans="";
        bool flag=false;
        string check="";
        for(int i=0;i<s.size();i++){
            if(s[i]==')'){
                flag=false;
                if(m.find(check)!=m.end()){
                    ans+=m[check];
                }
                else{
                    ans+='?';
                }
                check="";
                continue;
            }
            if(flag){
                check+=s[i];
                continue;
            }
            else if(s[i]=='('){
                flag=true;
                continue;
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};
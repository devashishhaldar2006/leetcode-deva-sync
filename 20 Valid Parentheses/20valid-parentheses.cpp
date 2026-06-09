class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto a:s){
            if(a=='(' || a=='[' || a=='{'){
                st.push(a);
            }
            else{
                if(st.size()==0) return false;
                if(a == ')' && st.top() != '(') return false;
                if(a == ']' && st.top() != '[') return false;
                if(a == '}' && st.top() != '{') return false;
                st.pop();
            }
        }
        return st.size()==0;
    }
};
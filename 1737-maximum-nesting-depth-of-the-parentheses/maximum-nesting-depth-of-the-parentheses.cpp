class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int cntA=0;
        int mx=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') {
                cntA++;
                mx=max(mx,cntA);
            }
            else if(s[i]==')') {
                mx=max(mx,cntA);
                cntA--;
            } 
        }
        return mx;
    }
};
class Solution {
public:
    void revPart(string& s,int i,int j){
        while(i<=j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        if(s==goal) return true;
        int n=s.size();
        int cnt=1;
        while(cnt<=n){
            string temp=s;
            revPart(temp,0,cnt-1);
            revPart(temp,cnt,n-1);
            revPart(temp,0,n-1);
            if(temp==goal) return true;
            cnt++;
        }
        return false;
    }
};
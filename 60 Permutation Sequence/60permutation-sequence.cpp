class Solution {
public:
    string helper(string ans,string str,int k){
        int n=str.length();
        if(str.length()==1){
            ans+=str;
            return ans;
        }
        int fact=1;
        for(int i=2;i<n;i++){
            fact*=i;
        }
        int idx=k/fact;
        if(k%fact==0) idx--;
        char ch=str[idx];
        string left=str.substr(0,idx);
        string right=str.substr(idx+1);
        int q=1;
        if(k%fact==0) q=fact;
        else q=k%fact;
        return helper(ans+ch,left+right,q);
    }
    string getPermutation(int n, int k) {
        string s="";
        for(int i=1;i<=n;i++){
            s+=(to_string(i));
        }
        return helper("",s,k);
    }
};
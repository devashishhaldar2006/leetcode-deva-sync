class Solution {
public:
    string lexSmallest(string s) {
        int n=s.size();
        string ans=s;
        for(int i=1;i<=n;i++){
            string temp=s;
            reverse(temp.begin(),temp.begin()+i);
            ans=min(ans,temp);
        }
        for(int i=1;i<=n;i++){
            string temp=s;
            reverse(temp.end()-i,temp.end());
            ans=min(ans,temp);
        }
        return ans;
        
    }
};
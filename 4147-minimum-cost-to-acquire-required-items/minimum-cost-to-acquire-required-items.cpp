class Solution {
public:
    typedef long long ll;
    long long minimumCost(int c1, int c2, int cb, int n1, int n2) {
        ll common=min(n1, n2);
        ll ans=0;
        ans+=common*min((ll)cb,(ll)c1 + c2);
        if(n1>n2) {
            ans+=(ll)(n1-n2)*min(c1,cb);
        }
        else{
            ans+=(ll)(n2-n1)*min(c2,cb);
        }
        return ans;
        

    }
};
class Solution {
public:
    void fillSieve(vector<int>& v){
        int n=v.size()-1;
        for(int i=2;i<=sqrt(n);i++){
            for(int j=i*2;j<=n;j+=i){
                v[j]=0;
            }
        }
        return;
    }
    int countPrimes(int n) {
        if(n<=2) return 0;
        n=n-1;
        vector<int> sieve(n+1,1);
        fillSieve(sieve);
        sieve[0]=0;
        sieve[1]=0;
        int count=0;
        for(int i=2;i<=n;i++){
            if(sieve[i]==1) count++;
        }
        return count;
    }
};
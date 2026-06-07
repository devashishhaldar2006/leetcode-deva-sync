class Solution {
public:
    void fillSieve(vector<int>& sieve){
        int n=sieve.size()-1;
        for(int i=2;i<=sqrt(n);i++){
            for(int j=i*i;j<=n;j+=i){
                sieve[j]=0;
            }
        }
        return;
    }
    int distinctPrimeFactors(vector<int>& nums) {
        int n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        vector<int> sieve(mx+1,1);
        fillSieve(sieve);
        if(mx+1>0) sieve[0]=0;
        if(mx+1>1) sieve[1]=0;
        vector<int> prime;
        for(int i=2;i<=mx;i++){
            if(sieve[i]) prime.push_back(i);
        }
        vector<bool> taken(prime.size(),0);
        for(int i=0;i<n;i++){
            int ele=nums[i];
            for(int j=0;j<prime.size();j++){
                if(prime[j]>ele) break;
                if(ele%prime[j]==0){
                    taken[j]=1;
                }
            }
        }
        int count=0;
        for(int i=0;i<taken.size();i++){
            if(taken[i]==1) count++;
        }
        return count;

    }
};
class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& arr) {
        long long n=arr.size();
        long long mx=arr[0];
        vector<long long> conv(n);
        long long i=0;
        while(i<n){
            if(arr[i]>mx){
                mx=arr[i];
            }
            conv[i]=arr[i]+mx;
            i++;
        }
        for(long long i=1;i<n;i++){
            conv[i]+=conv[i-1];
        }   
        return conv;
    }
};
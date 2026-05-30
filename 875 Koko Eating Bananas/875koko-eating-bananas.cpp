class Solution {
public:
    bool check(vector<int>& p,int m,int h){
        int count=0;
        int n=p.size();
        for(int i=0;i<n;i++){
            if(count>h) return false;
            if(m>=p[i]) count++;
            else if(p[i]%m==0) count+=p[i]/m;
            else count+=p[i]/m+1;
        }
        return count<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo=1;
        int hi=*max_element(piles.begin(),piles.end());
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(piles,mid,h)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};
class Solution {
public: 
    bool check(long long mid,vector<int>& time, int totalTrips){
        long long trips=0;
        int n=time.size();
        for(int i=0;i<n;i++){
            trips+=mid/(long long)time[i];
        }
        return trips>=totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n=time.size();
        long long mx=*max_element(time.begin(),time.end());
        long long lo=1;
        long long ans=-1;
        long long hi=(long long)mx*(long long)totalTrips;
        while(lo<=hi){
            long long mid=lo+(hi-lo)/2;
            if(check(mid,time,totalTrips)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};
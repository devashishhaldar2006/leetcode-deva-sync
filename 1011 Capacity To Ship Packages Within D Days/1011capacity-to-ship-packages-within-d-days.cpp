class Solution {
public:
    bool check(vector<int>& w,int d,int mid){
        int i=0;
        int t=mid;
        int count=1;
        for(int i=0;i<w.size();i++){
            if(w[i]<=mid){
                mid=mid-w[i];
            }
            else {
                count++;
                mid=t;
                mid=mid-w[i];
            }
        }
        return count<=d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int lo=*max_element(weights.begin(),weights.end());
        int hi=accumulate(weights.begin(),weights.end(),0);
        int ans=hi;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(weights,days,mid)){
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
};
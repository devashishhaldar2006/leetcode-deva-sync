class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        vector<int> suf(n);
        suf[n-1]=satisfaction[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i]=suf[i+1]+satisfaction[i];
        }
        int pivot=-1;
        for(int i=0;i<n;i++){
            if(suf[i]>=0){
                pivot=i;
                break;
            }
        }
        if(pivot==-1) return 0;
        int satisfy=0;
        int x=1;
        for(int i=pivot;i<n;i++){
            satisfy+=(satisfaction[i]*x);
            x++;
        }
        return satisfy;
    }
};
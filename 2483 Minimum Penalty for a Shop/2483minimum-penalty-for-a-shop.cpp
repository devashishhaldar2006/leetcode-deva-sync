class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        vector<int> pre(n+1),suff(n+1);
        int count=0;
        for(int i=1;i<=n;i++){
            if(customers[i-1]=='N') count++;
            pre[i]=count;
        }
        suff[n]=0;
        for(int i=n-1;i>=0;i--){
            suff[i]=suff[i+1];
            if(customers[i]=='Y') suff[i]++;
        }
        for(int i=0;i<=n;i++){
            pre[i]+=suff[i];
        }
        int minPen=INT_MAX;
        for(int i=0;i<=n;i++){
            minPen=min(minPen,pre[i]);
        }

        for(int i=0;i<=n;i++){
            if(pre[i]==minPen) return i;
        }

        return -1;
    }
};
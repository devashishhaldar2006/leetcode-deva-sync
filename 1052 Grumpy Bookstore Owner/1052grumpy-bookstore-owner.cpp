class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int prevLoss=0;
        for(int i=0;i<minutes;i++){
            prevLoss+=(grumpy[i]==1 ? customers[i] : 0); 
        }
        int maxLoss=prevLoss;
        int i=1;
        int j=minutes;
        int lossIdx=0;
        while(j<n){
            int currLoss=prevLoss+( grumpy[j]==1 ? customers[j] : 0 ) - ( grumpy[i-1]==1 ? customers[i-1] : 0);
            if(maxLoss<currLoss){
                maxLoss=currLoss;
                lossIdx=i;
            }
            prevLoss=currLoss;
            i++;
            j++;
        }
        for(int i=lossIdx;i<minutes+lossIdx;i++){
            grumpy[i]=0;
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=(grumpy[i]==0 ? customers[i] : 0); 
        }
        return sum;
    }
};
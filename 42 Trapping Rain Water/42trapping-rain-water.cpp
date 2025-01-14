class Solution {
public:
    int trap(vector<int>& height) {
    
        int n=height.size();
        //previous greatest element array
        int prev[n];
        prev[0]=-1;
        int max=height[0];
        for(int i=1;i<n;i++){
            prev[i]=max;
                if(height[i]>max){
                    max=height[i];
                }
        }
        //next greatest element array
        prev[n-1]=-1;
        max=height[n-1];
        for(int i=n-2;i>=0;i--){
            if(max<prev[i]) prev[i]=max;
            if(height[i]>max){
                max=height[i];
            }
        }
        int water=0;
        for(int i=0;i<n;i++){
            if(prev[i]>height[i]){
                water+=prev[i]-height[i];
            }
        }
        return water;
    }
};
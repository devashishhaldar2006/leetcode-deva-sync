class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int start=nums[i];
            int end=start;
            while(i+1<n and ((long long)nums[i+1]-nums[i])==1){
                i++;
                end=nums[i];
            }
            if(end==start){
                ans.push_back(to_string(start));
            }
            else ans.push_back(to_string(start)+"->"+to_string(end));

        }
        return ans;
    }
};
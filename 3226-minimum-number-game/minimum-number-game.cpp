class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        priority_queue<int,vector<int>,greater<int> > pq;
        for(auto num:nums) pq.push(num);
        while(pq.size()){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            ans.push_back(y);
            ans.push_back(x);
        }
        return ans;
         
    }
};
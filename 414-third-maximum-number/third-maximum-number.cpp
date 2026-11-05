class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n=nums.size();
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }
        int x=0;
        if(pq.size()) {
            x=pq.top();
            pq.pop();
            while(pq.size() and x==pq.top()) pq.pop();
        }
        int y=0;
        if(pq.size()) {
            y=pq.top();
            pq.pop();
            while(pq.size() and y==pq.top()) pq.pop();
        }
        if(pq.size()) return pq.top();
        return x;

    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==1) return nums;
        vector<int> ans;
        deque<int> dq;
        for(int i=0;i<n;i++){
            while(dq.size() && nums[dq.back()]<nums[i]) dq.pop_back();
            dq.push_back(i);
            int j=i-k+1;
            while(dq.front()<j) dq.pop_front();
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }

};
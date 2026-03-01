class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n,0);
        for(auto book:bookings){
            int l=book[0]-1;
            int r=book[1]-1;
            ans[l]+=book[2];
            if (r + 1 < n) ans[r + 1] -= book[2];
        }
        for(int i=1;i<n;i++){
            ans[i]+=ans[i-1];
        }
        return ans;
    }
};

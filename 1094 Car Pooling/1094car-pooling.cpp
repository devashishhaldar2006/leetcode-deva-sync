class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n=trips.size();
        vector<int> dist(1001,0);

        for(int i=0;i<n;i++){
            int passenger=trips[i][0];
            int from=trips[i][1];
            int to=trips[i][2];

            dist[from]+=passenger;
            dist[to]-=passenger;
        }
        int curr=0;
        for(int i=0;i<=1000;i++){
            curr+=dist[i];
            if(curr>capacity){
                return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int src) {
        vector<int> dist(n+1,INT_MAX);
        dist[src]=0;
        for(int x=1;x<=n;x++){
            for(int i=0;i<times.size();i++){
                int u=times[i][0];
                int v=times[i][1];
                int wt=times[i][2];
                if(dist[u]!=INT_MAX and dist[u]+wt < dist[v]) {
                    dist[v]=dist[u] + wt;
                }
            }
        }
        int mx=INT_MIN;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX) return -1;
            mx=max(mx,dist[i]);
        }
        return mx;
    }
};
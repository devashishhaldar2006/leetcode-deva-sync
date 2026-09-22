class Solution {
public:
    typedef pair<int,int> pr;
    int networkDelayTime(vector<vector<int>>& edges, int n, int src) {
        vector<vector<pr>> adj(n+1);
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];
            int w=edges[i][2];
            adj[a].push_back({b,w});
        }
        vector<int> dist(n+1,INT_MAX);
        dist[src]=0;
        priority_queue<pr,vector<pr>,greater<pr>> pq;
        pq.push({0,src});
        while(pq.size()){
            int node=pq.top().second;
            int distance=pq.top().first;
            pq.pop();
            if(distance>dist[node]) continue;
            for(auto p:adj[node]){
                int curr=p.first;
                int currDist=p.second;
                int totalDist=currDist+distance;
                if(totalDist<dist[curr]){
                    dist[curr]=totalDist;
                    pq.push({totalDist,curr});
                }
            }
        }
        int mx=*max_element(dist.begin()+1,dist.end());
        if(mx==INT_MAX) return -1;
        return mx;
        
    }
};
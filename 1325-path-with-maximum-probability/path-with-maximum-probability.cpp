class Solution {
public:
    typedef pair<int,double> pr;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int src, int end) {
        vector<vector<pr>> adj(n);
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];
            double w=succProb[i];
            adj[a].push_back({b,w});
            adj[b].push_back({a,w});
        }
        priority_queue<pair<double,int>> pq;
        vector<double> dist(n,0.0);
        dist[src]=1.0;
        pq.push({1.0,src});
        while(pq.size()){
            int node=pq.top().second;
            double distance=pq.top().first;
            pq.pop();
            if(distance<dist[node]) continue;
            for(auto p:adj[node]){
                int curr=p.first;
                double currDist=p.second;
                double totalDist=currDist*distance;
                if(totalDist>dist[curr]){
                    dist[curr]=totalDist;
                    pq.push({totalDist,curr});
                }
            }
        }
        return dist[end];

    }
};
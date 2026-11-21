class Solution {
public:
    typedef pair<int,pair<int,int>> pr;
    int bfs(vector<vector<pair<int,int> > >& adj,vector<int>& fee,int maxTime){
        int n=fee.size();
        vector<int> minTime(n,INT_MAX);
        priority_queue<pr,vector<pr>,greater<pr> > pq;
        pq.push({fee[0],{0,0}});
        minTime[0]=0;
        while(pq.size()){
            int cost=pq.top().first;
            int time=pq.top().second.first;
            int u=pq.top().second.second;
            pq.pop();
            if(u==n-1) return cost;
            for(auto edge:adj[u]){
                int v=edge.first;
                int travelTime=edge.second;
                if(time+travelTime<=maxTime) {
                    if(time+travelTime<minTime[v]) {
                        minTime[v]=time+travelTime;
                        pq.push({cost+fee[v],{time+travelTime,v}});
                    }
                }
            }
        }
        return -1;

    }
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& fee) {
        int n=fee.size();
        vector<vector<pair<int,int> > > adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        return bfs(adj,fee,maxTime);
    }
};
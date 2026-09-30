class Solution {
public:
    typedef pair<int,pair<int,int> > pr;
    int dj(int n,vector<vector<pair<int,int>>>& adj,int src,int dst,int k){
        priority_queue<pr,vector<pr>,greater<pr>> pq;
        vector<int> ans(n,INT_MAX);
        pq.push({0,{src,0}}); 
        ans[src]=0;
        while(pq.size()){
            int cost=pq.top().second.second;
            int node=pq.top().second.first;
            int stop=pq.top().first;
            pq.pop();
            if(stop==k+1) continue;
            for(auto p:adj[node]){
                int totalCost=cost+p.second;
                if(totalCost<ans[p.first]){
                    ans[p.first]=totalCost;
                    pq.push({stop+1,{p.first,totalCost}});
                }
            }
        }
        if(ans[dst]==INT_MAX) return -1;
        else return ans[dst];
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int m=flights.size();
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<m;i++){
            int a=flights[i][0];
            int b=flights[i][1];
            int price=flights[i][2];
            adj[a].push_back({b,price});
        }
        return dj(n,adj,src,dst,k);

    }
};
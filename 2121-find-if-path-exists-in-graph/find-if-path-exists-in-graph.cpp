class Solution {
public:
    void bfs(int i,vector<int>& visit,vector<vector<int>>& adj){
        visit[i]=1;
        queue<int> q;
        q.push(i);
        while(q.size()){
            int front=q.front();
            q.pop();
            for(auto ele:adj[front]){
                if(visit[ele]==0) {
                    visit[ele]=1;
                    q.push(ele);
                }
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination) return true;
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> visit(n,0);
        bfs(source,visit,adj);
        return visit[destination];
    }
};
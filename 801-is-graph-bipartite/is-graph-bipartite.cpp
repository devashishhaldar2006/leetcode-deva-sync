class Solution {
public:
    bool flag;
    void bfs(int i,vector<vector<int>>& graph,vector<int>& vis){
        int n=graph.size();
        vis[i]=0;
        queue<int> q;
        q.push(i);
        while(q.size()){
            int front=q.front();
            int color=vis[front];
            q.pop();
            for(auto ele:graph[front]){
                if(vis[ele]==vis[front]){
                    flag=false;
                    return;
                }
                if(vis[ele]==-1){
                    vis[ele]=1-color;
                    q.push(ele);
                }
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,-1);
        flag=true;
        for(int i=0;i<n;i++){
            if(flag==false) return flag;
            if(vis[i]==-1) bfs(i,graph,vis);
        }
        return flag;
    }
};
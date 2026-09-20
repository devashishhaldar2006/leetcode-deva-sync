class Solution {
public:
    void bfs(int i,vector<int>& visit,vector<vector<int>>& adj){
        int n=adj.size();
        queue<int> q;
        q.push(i);
        visit[i]=1;
        while(q.size()){
            int front=q.front();
            q.pop();
            for(int j=0;j<n;j++){
                if(adj[front][j]==1 and visit[j]==0){
                    visit[j]=1;
                    q.push(j);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> visit(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(visit[i]==0){
                bfs(i,visit,adj);
                cnt++;
            }
        }
        return cnt;
    }
};
class Solution {
public:
    void dfs(int i,vector<vector<int>>& adj,vector<int>& visit){
        visit[i]=1;
        int n=adj.size();
        for(int j=0;j<n;j++){
            if(visit[j]==0 and adj[i][j]==1){
                dfs(j,adj,visit);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> visit(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(visit[i]==0){
                dfs(i,adj,visit);
                cnt++;
            }
        }
        return cnt;
    }
};
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>> adj(n+1);
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int count=0;
        int ans=0;
        for(int i=1;i<=n;i++){
            int cnt=adj[i].size();
            if(cnt>count){
                count=cnt;
                ans=i;
            }
        }
        return ans;

    }
};
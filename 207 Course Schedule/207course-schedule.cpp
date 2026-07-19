class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(int i=0;i<pre.size();i++){
            int a=pre[i][0];
            int b=pre[i][1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        // kahn's algo
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int cnt=0;
        while(q.size()){
            int front=q.front();
            q.pop();
            cnt++;
            for(auto ele:adj[front]){
                indegree[ele]--;
                if(indegree[ele]==0){
                    q.push(ele);
                }
            }
        }
        return cnt==n;
    }
};
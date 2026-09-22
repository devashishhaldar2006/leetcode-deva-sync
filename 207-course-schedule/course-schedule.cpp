class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        int m=pre.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(int i=0;i<m;i++){
            int a=pre[i][0];
            int b=pre[i][1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(q.size()){
            int front=q.front();
            q.pop();
            ans.push_back(front);
            for(auto ele:adj[front]){
                indegree[ele]--;
                if(indegree[ele]==0){
                    q.push(ele);
                }
            }
        }
        return ans.size()==n;
    }
};
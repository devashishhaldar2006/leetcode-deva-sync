class Solution {
public:
    void bfs(int i,vector<int>& visit,vector<vector<int>>& rooms){
        int n=rooms.size();
        visit[i]=1;
        queue<int> q;
        q.push(i);
        while(q.size()){
            int front=q.front();
            q.pop();
            for(auto ele:rooms[front]){
                if(visit[ele]==0){
                    visit[ele]=1;
                    q.push(ele);
                }
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> visit(n,0);
        bfs(0,visit,rooms);
        for(int i=0;i<n;i++){
            if(visit[i]==0) return false;
        }
        return true;
    }
};
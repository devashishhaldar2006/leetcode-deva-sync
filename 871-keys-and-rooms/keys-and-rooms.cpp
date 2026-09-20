class Solution {
public:
    void bfs(int i,vector<int>& visit,vector<vector<int>>& rooms){
        visit[i]=1;
        queue<int> q;
        q.push(i);
        while(q.size()){
            int front=q.front();
            q.pop();
            for(int j=0;j<rooms[front].size();j++){
                if(visit[rooms[front][j]]==0){
                    visit[rooms[front][j]]=1;
                    q.push(rooms[front][j]);
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
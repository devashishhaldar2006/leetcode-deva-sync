class Solution {
public:
    void dfs(int i,vector<vector<int>>& rooms,vector<int>& visit){
        visit[i]=1;
        for(int j=0;j<rooms[i].size();j++){
            if(visit[rooms[i][j]]==0){
                dfs(rooms[i][j],rooms,visit);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> visit(n,0);
        dfs(0,rooms,visit);
        for(int i=0;i<n;i++){
            if(visit[i]==0) return false;
        }
        return true;
    }
};
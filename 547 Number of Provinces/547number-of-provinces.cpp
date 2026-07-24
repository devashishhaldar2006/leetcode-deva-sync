class Solution {
public:
    vector<int> parent;
    vector<int> size;
    int find(int a){
        if(parent[a]==a) return a;
        return parent[a]=find(parent[a]);
    }
    void unionEdges(int a,int b){
        a=find(a);
        b=find(b);
        if(a!=b){
            if(size[a]>size[b]){ //a should be parent of b
                parent[b]=a;
                size[a]+=size[b];
            }
            else{
                parent[a]=b;
                size[b]+=size[a];
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        parent.resize(n+1,0);
        size.resize(n+1,0);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                // edge is from i+1 to j+1
                if(i!=j and isConnected[i][j]) unionEdges(i+1,j+1); //connecting group leaders
            }
        }
        int count=0;
        for(int i=1;i<=n;i++){
            if(parent[i]==i) count++;
        }
        return count;

    }
};
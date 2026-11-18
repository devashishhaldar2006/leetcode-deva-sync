class SeatManager {
public:
    priority_queue<int,vector<int>,greater<int> > mn;
    SeatManager(int n) {
        for(int i=1;i<=n;i++){
            mn.push(i);
        }
    }
    
    int reserve() {
        int x=mn.top();
        mn.pop();
        return x;
    }
    
    void unreserve(int s) {
        mn.push(s);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
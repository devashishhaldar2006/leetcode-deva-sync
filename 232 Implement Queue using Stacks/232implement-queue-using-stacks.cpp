class MyQueue {
public:
    stack<int> st;
    stack<int> helper;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(st.size()){
            helper.push(st.top());
            st.pop();
        }
        st.push(x);
        while(helper.size()){
            st.push(helper.top());
            helper.pop();
        }
        return;
    }
    
    int pop() {
        int x=st.top();
        st.pop();
        return x;
    }
    
    int peek() {
        int x=st.top();
        return x;
    }
    
    bool empty() {
        return st.size()==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
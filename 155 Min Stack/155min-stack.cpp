class MinStack {
public:
    stack<long long> st;
    long long mn;
    MinStack() {
       mn=LLONG_MAX;
    }
    
    void push(long long value) {
        if(!st.size()){
            st.push(value);
            mn=value;
        }
        else if(value<mn){
            st.push(2*value-mn);
            mn=value;
        }
        else st.push(value);
    }
    
    void pop() {
        if(st.top()<mn){
            long long oldmin=(2*mn-st.top());
            mn=oldmin;
        }
        st.pop();
    }
    
    long long top() {
        if(st.top()<mn) return mn;
        return st.top();
    }
    
    long long getMin() {
        return mn;
    }
};
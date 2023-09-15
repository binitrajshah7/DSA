class MinStack {
public:
    int minm;
    // here first int will represent value and second will store minimum at every point in stack
    vector<pair<int, int>> st;
    MinStack() {}
    void push(int val) {
        if(st.empty())
            st.push_back({val, val});                
        else
            st.push_back({val, min(st.back().second, val)});
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.back().first;
    }
    
    int getMin() {
        return st.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
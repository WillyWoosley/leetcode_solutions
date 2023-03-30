class MinStack {
private:
    stack<pair<int, int>> min_stack;
    int cur_min = INT_MAX;
public:
    MinStack() {}
    
    void push(int val) {
        if (val < cur_min) {
            cur_min = val;
        }
        min_stack.push(make_pair(val, cur_min));
    }
    
    void pop() {
        min_stack.pop();
        if (min_stack.empty()) {
            cur_min = INT_MAX;
        } else {
            cur_min = min_stack.top().second;
        }
        
    }
    
    int top() {
        return min_stack.top().first;
    }
    
    int getMin() {
        return min_stack.top().second;
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

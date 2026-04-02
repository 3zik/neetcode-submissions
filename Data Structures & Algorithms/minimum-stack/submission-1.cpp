class MinStack {
public:
    std::stack<int> stk;
    std::stack<int> miniStk;
    MinStack() {

    }
    
    void push(int val) {
        stk.push(val);
        miniStk.empty() ? miniStk.push(val) : 
            miniStk.push(min(miniStk.top(), val));
    }
    
    void pop() {
        stk.pop();
        miniStk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return miniStk.top();
    }
};

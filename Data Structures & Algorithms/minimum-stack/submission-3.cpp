class MinStack {
private:
    std::stack<int> s;
    std::stack<int> minStack;
public:
    MinStack() {}
    
    void push(int val) {
        s.push(val);
        if ((!minStack.empty()) && (minStack.top() < val)){
            minStack.push(minStack.top());
        } else {
            minStack.push(val);
        }
    }
    
    void pop() {
        s.pop();
        minStack.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

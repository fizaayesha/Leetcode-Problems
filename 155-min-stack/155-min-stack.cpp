class MinStack {
public:
    stack <int> s1;
    stack <int> s2;
    MinStack() {
        
    }
    
    void push(int val) {
        s1.push(val);
        if(s2.size()==0){
            s2.push(val);
        }
        else{
            if(s2.top()<val){
                s2.push(s2.top());
            }
            else{
                s2.push(val);
            }
        }
    }
    
    void pop() {
        s1.pop();
        s2.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
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
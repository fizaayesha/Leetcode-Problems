class MyStack {
public:
    queue<int> q1,q2;
    MyStack() {
        
    }
    
    void push(int x) {
        if(q1.empty()){
            q1.push(x);
        }
        else{
            while(!q1.empty()){
                int y=q1.front();
                q2.push(y);
                q1.pop();
            }
            q1.push(x);
            while(!q2.empty()){
                int y=q2.front();
                q1.push(y);
                q2.pop();
            }
        }
    }
    
    int pop() {
        if(q1.empty()){
            return -1;
        }
        else{
            int x=q1.front();
            q1.pop();
            return x;
        }
    }
    
    int top() {
        if(q1.empty()){
            return -1;
        }      
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
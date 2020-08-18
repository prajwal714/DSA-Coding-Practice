class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    stack<int> temp;
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        
        if(temp.empty())
            temp.push(x);
        else if(x<=temp.top())
            temp.push(x);         
    }
    
    void pop() {
        if(s.empty())
            return;
        
        if(s.top()==temp.top())
            temp.pop();
        
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return temp.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

//===========================================O(1) space complexity solution


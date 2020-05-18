 stack<int> s;
stack<int> ss;
MinStack::MinStack() {
    
   while(!s.empty())
   s.pop();
   
   while(!ss.empty())
   ss.pop();
    
}

void MinStack::push(int x) {
    s.push(x);
    if(ss.empty()||ss.top()>x)
    ss.push(x);
}

void MinStack::pop() {
    
    if(s.empty())
    return;
    
    if(s.top()==ss.top())
    {
        s.pop();
        ss.pop();
    }
    else
    s.pop();
}

int MinStack::top() {
    
    if(s.empty())
    return -1;
    
    return s.top();
}

int MinStack::getMin() {
    
    if(ss.empty())
    return -1;
    
    return ss.top();
}



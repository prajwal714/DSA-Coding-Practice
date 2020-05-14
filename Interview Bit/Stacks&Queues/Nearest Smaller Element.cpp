vector<int> Solution::prevSmaller(vector<int> &A) {
    
    vector<int> sol;
    
    stack<int> s;
    
    int i, n=A.size();
    
    for(i=0;i<n;i++)
    {
        if(s.empty())
        {
            sol.push_back(-1);
        }
        else if(s.top()<A[i])
        {
            sol.push_back(s.top());
        }
        else
        {
            while(!s.empty()&&s.top()>=A[i])
            {
                s.pop();
            }
            
            if(s.empty())
            sol.push_back(-1);
            else
            sol.push_back(s.top());
        }
        
        s.push(A[i]);
    }
    
    return sol;
}


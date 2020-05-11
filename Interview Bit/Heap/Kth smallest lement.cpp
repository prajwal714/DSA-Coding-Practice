int Solution::kthsmallest(const vector<int> &A, int B) {
    
    priority_queue<int> pq;
    
    int i;
    for(i=0;i<B;i++)
    {
        pq.push(A[i]);
    }
    
    for(i=B;i<A.size();i++)
    {
        if(A[i]<pq.top())
        {
            pq.pop();
            pq.push(A[i]);
        }
    }
    
    return pq.top();
    
    
}


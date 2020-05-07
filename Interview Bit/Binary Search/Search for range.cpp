vector<int> Solution::searchRange(const vector<int> &A, int B) {
    
    int firstOcc=-1;
    int lastOcc=-1;
    
    int start=0;
    int end=A.size()-1;
    
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        
        if(A[mid]==B)
        {
            firstOcc=mid;
            end=mid-1;
        }
        else if(B<A[mid])
        {
            end=mid-1;
        }
        else
        start=mid+1;
    }
    
    start=0; end=A.size()-1;
    
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        
        if(A[mid]==B)
        {
            lastOcc=mid;
            start=mid+1;
        }
        else if(B<A[mid])
        {
            end=mid-1;
        }
        else
        start=mid+1;
    }
    
    vector<int> sol;
    sol.push_back(firstOcc);
    sol.push_back(lastOcc);
    
    return sol;
    
}


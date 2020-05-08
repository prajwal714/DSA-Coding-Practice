int Solution::sqrt(int A) {
    
    int start=1, end=A;
    int res;
    
    if(A==0)
    return 0;
    
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        
        if(mid==A/mid)
        {
       return mid;
            
        }
        
        else if(mid<A/mid)
        {
            res=mid;
            start=mid+1;
        }
        else
        end=mid-1;
    }
    return res;
    
    
}


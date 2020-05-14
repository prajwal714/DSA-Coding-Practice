int Solution::maxArea(vector<int> &A) {
    long long int res=0;
    long long int sum=0;
    
    int start=0,end=A.size()-1;
    
    while(start<end)
    {
        sum=(end-start)*min(A[start],A[end]);
        
        if(sum>res)
        res=sum;
        if(A[start]<A[end])
        {
            start++;
        }
        else if(A[start]>=A[end])
        {
            end--;
        }
       
    }
    
    return res;
}

=========================================================================



int Solution::threeSumClosest(vector<int> &A, int B) {
    
    int i,curr,start,end;
    int sum=0, res=INT_MAX, ans;
    sort(A.begin(), A.end());
    for(i=A.size()-1;i>=2;i--)
    {
        curr=A[i];
        start=0; end=i-1;
        while(start<end)
        {
            sum=A[start]+A[end]+curr;
            
            if(abs(sum-B)<res)
            {
                res=abs(sum-B);
                ans=sum;
            }
            
            if(sum<B)
            start++;
            else if(sum>B)
            end--;
            else
            return sum;
        }
    }
    return ans;
    
}


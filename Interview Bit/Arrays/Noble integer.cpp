int Solution::solve(vector<int> &A) {
    sort(A.begin(), A.end());
    int n=A.size();
    for(int i=0;i<n;i++)
    {
        int idx=upper_bound(A.begin(), A.end(), A[i])-A.begin();
        if(A[i]==(n-idx))
        return 1;
    }
    
    return -1;
}

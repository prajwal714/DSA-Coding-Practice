vector<int> Solution::wave(vector<int> &A) {
    sort(A.begin(), A.end());
    int n=A.size();
    vector<int> res;
    int size=n;
    if(n%2==1)
    size=n-1;
    
    for(int i=0;i<size;i+=2)
    {
       swap(A[i],A[i+1]);
    }
    
    return A;
}


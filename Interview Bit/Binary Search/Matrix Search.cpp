int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    
    int m=A.size();
    int n=A[0].size();
    int i=0,j=n-1;
    
    while(i>=0 && i<m && j>=0 && j<n)
    {
        if(B==A[i][j])
        return 1;
        
        else if(B<A[i][j])
        j--;
        
        else 
        i++;
    }
    
    return 0;
}


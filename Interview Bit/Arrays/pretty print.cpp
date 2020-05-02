vector<vector<int> > Solution::prettyPrint(int num) {
    int n=2*num-1;
    
    vector<vector<int> > A(n);
    
    
    int val=num;
    int top=0, bottom=n-1,right=n-1,left=0;
    
    int i,j;
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        A[i].push_back(0);
    }
    
    
    while(top<=bottom && left<=right)
    {
        for(i=left;i<=right;i++)
        A[top][i]=val;
        top++;
        
        for(i=top;i<=bottom;i++)
        A[i][right]=val;
        right--;
        
        for(i=right;i>=left;i--)
        A[bottom][i]=val;
        bottom--;
        
        for(i=bottom;i>=top;i--)
        A[i][left]=val;
        left++;
        
        val--;
        
        
    }
    
    return A;
    
    
}


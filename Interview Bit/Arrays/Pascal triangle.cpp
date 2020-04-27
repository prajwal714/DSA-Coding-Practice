vector<vector<int> > Solution::solve(int A) {
    int row=A;
    
    
    
    vector<vector<int>> arr(row);
    
    if(row>0)
    arr[0].push_back(1);
    
    int i;
    for(i=1;i<row;i++)
    {
        arr[i].push_back(1);
        for(int j=1;j<i+1;j++)
        {
            if(j==i)
            arr[i].push_back(1);
            else
            arr[i].push_back(arr[i-1][j]+arr[i-1][j-1]);
        }
    }
    return arr;
}

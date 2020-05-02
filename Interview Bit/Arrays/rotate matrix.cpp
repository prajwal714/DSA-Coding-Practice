void Solution::rotate(vector<vector<int> > &arr) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i,j;
    int n=arr[0].size();
    
    for(i=0;i<n/2;i++)
    {
        for(j=i;j<n-1-i;j++)
        {
            int temp=arr[i][j];
            arr[i][j]=arr[n-1-j][i];
            arr[n-1-j][i]=arr[n-1-i][n-1-j];
            arr[n-1-i][n-1-j]=arr[j][n-1-i];
            arr[j][n-1-i]=temp;
        }
    }
    
    
}


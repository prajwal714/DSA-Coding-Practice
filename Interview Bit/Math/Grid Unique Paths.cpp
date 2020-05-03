int Solution::uniquePaths(int A, int B) {
    int dp[A][B];
    
    int i,j;
    for(i=0;i<A;i++)
    {
        for(j=0;j<B;j++)
        {
            if(i==0||j==0)
            dp[i][j]=1;
        }
    }
    
    for(i=1;i<A;i++)
    {
        for(j=1;j<B;j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    
    return dp[A-1][B-1];
    
}

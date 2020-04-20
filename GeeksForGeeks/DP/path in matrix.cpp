#include<iostream>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int dp[n][n];
	    int i,j;
	    for(i=0;i<n;i++)
	    {
	        for(j=0;j<n;j++)
	        cin>>dp[i][j];
	    }
	    
	    
	    for(i=1;i<n;i++)
	    {
	        for(j=0;j<n;j++)
	        {
	            if(j==0)
	            dp[i][j]+=max(dp[i-1][j],dp[i-1][j+1]);
	            else if(j==n-1)
	            dp[i][j]+=max(dp[i-1][j],dp[i-1][j-1]);
	            else
	            dp[i][j]+=max(dp[i-1][j],max(dp[i-1][j-1],dp[i-1][j+1]));
	        }
	    }
	    int res=0;
	    for(i=0;i<n;i++)
	    {
	        res=max(res,dp[n-1][i]);
	    }
	    cout<<res<<endl;
	}
	return 0;
}

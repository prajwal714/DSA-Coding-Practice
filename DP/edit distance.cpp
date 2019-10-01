#include<iostream>
#include<bits/stdc++.h>

//make string s1==s2 by either removind,adding or replacing characters and minimize the editing
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int m,n;
	    cin>>m>>n;
	    string s1,s2;
	    cin>>s1>>s2;
	    
	    int dp[m+1][n+1];
	    int i,j;
	    for(i=0;i<=m;i++)
	    {
	        for(j=0;j<=n;j++)
	        {
	            if(i==0||j==0)
	            dp[i][j]=max(i,j);
	            
	            else if(s1[i-1]==s2[j-1])
	            {
	                dp[i][j]=dp[i-1][j-1];
	            }
	            else
	            dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
	        }
	    }
	    
	   
	    cout<<dp[m][n]<<endl;
	  
	    
	}
	return 0;
}

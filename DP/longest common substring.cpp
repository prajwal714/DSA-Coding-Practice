#include<bits/stdc++.h>
using namespace std;

int main()
{
	int m,n;
	cin>>m>>n;
	string s1,s2;
	cin>>s1>>s2;
	
	int dp[m+1][n+1];
	
	int i,j;
	int res=0;
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(i==0||j==0)
			dp[i][j]=0;
			
			else if(s1[i-1]==s2[j-1])
			{
				dp[i][j]=1+dp[i-1][j-1];
				res=max(res,dp[i][j]);
				
			}
			else
			dp[i][j]=0;
		}
	}
	cout<<res<<endl;
}


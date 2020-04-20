#include<bits/stdc++.h>
using namespace std;

int main()
{
	

		int m,n;
		cin>>m>>n;
		string s1,s2;
		cout<<"Enter string1: ";
		cin>>s1;
		cout<<"Enter string2 : ";
		cin>>s2;
		
		
		 int dp[m+1][n+1];
		 
		 int i,j;
		 for(i=0;i<=m;i++)
		 {
		 	for(j=0;j<=n;j++)
		 	{
		 		if(i==0||j==0)
		 		dp[i][j]=0;
		 		
		 		else if (s1[i-1]==s2[j-1])
		 		dp[i][j]=dp[i-1][j-1]+1;
		 		
		 		else
		 		{
		 			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				 }
			 }
		 }
		 cout<<"length of common subsequence: "<<endl;
		 cout<<dp[m][n]<<endl;
		i=m;j=n;
		
		 char lcs[dp[m][n]];
		 
		 while(i>0&&j>0)
		 {
		 	if(s1[i]==s2[j])
		 	{
		 		cout<<s1[i];
		 		i--;
		 		j--;
			 }
			 else
			 {
			 	if(dp[i-1][j]>dp[i][j-1])
			 	i--;
			 	else 
			 	j--;
			 
			 }
		 }
		
	return 0;
}

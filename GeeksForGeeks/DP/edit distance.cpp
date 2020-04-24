#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int editCost(string s1, string s2, int m, int n)
{
    int dp[m+1][n+1];
    
    int i,j;
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0||j==0)
            dp[i][j]=max(i,j);
            
            else if(s1[i-1]==s2[j-1])
            dp[i][j]=dp[i-1][j-1];
            
            else
            
            dp[i][j]=min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
        }
    }
    
    return dp[m][n];
}


int main()
 {
    IOS;
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int m,n;
	    cin>>m>>n;
	    string s1,s2;
	    cin>>s1>>s2;
	    
	    cout<<editCost(s1,s2,m,n)<<endl;
	    
	}
	return 0;
}

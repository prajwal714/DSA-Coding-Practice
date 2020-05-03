#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int wt;
	    cin>>wt;
	    
	    int coins[]={1,2};
	    
	    vector<long long int> dp(wt+1,0);
	    dp[0]=0;
	    dp[1]=1;
	    dp[2]=2;
	    
	    for(int i=3;i<=wt;i++)
	    {
	        dp[i]=dp[i-1]+dp[i-2];  
	    }
	    
	    cout<<dp[wt]<<endl;
	    
	    
	    
	}
	return 0;
}
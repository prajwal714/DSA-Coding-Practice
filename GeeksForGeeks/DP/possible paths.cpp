/* You are standing on a point (n, m) and you want to go to origin (0, 0) by taking steps either left or down i.e. 
from each point you are allowed to move either in (n-1, m) or (n, m-1). 
Find the number of paths from point to origin.*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long int pascal(int n,int r)
{
    long long int arr[n+1][r+1];
    
    
    
    int i,j;
    
    for(i=0;i<=n;i++)
    {
        for(j=1;j<=r;j++)
        {
            
           arr[i][j]=0;
        }
    }
    
    for(i=0;i<=n;i++)
    arr[i][0]=1;
    
    
   
    for(i=1;i<=n;i++)
    {
        
        for(j=1;j<i+1&&j<=r;j++)
        {
            arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
        }
    }
    return arr[n][r];
}


long long int nCr(int n,int r)
{
    if(r==0)
    return 1;
    
    if(n==r)
    return 1;
    
    return nCr(n-1,r-1)+nCr(n-1,r);
}

int main()
 {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int m,n;
	    cin>>m>>n;
	    
	    cout<<pascal(m+n,m);
	    cout<<endl;
	}
	return 0;
}

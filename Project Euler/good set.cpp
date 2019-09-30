#include<bits/stdc++.h>
using namespace std;
# define ll long long 
# define div 1000000007

long long val[2000][2000];
void nCr(int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        val[i][0]=1;
        for(j=1;j<n;j++)
        {
            val[i][j]=0;
        }
    }
    
    for(i=1;i<n;i++)
    {
        for(j=1;j<=i;j++)
        {
            val[i][j]=(val[i-1][j-1]+val[i-1][j])%div;
        }
    }
    
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
    	cout<<val[i][j]<<" ";
    	cout<<endl;
	}
}

int main()
{
     int n;
     cin>>n;
     nCr(n);
     int i;
      int size=max(n/2,n-n/2);
    ll fact[size];
    fact[0]=1;
    for(i=1;i<=size;i++)
    {
        fact[i]=i*fact[i-1]%div;
    }
    
    for(i=0;i<=size;i++)
    cout<<fact[i]<<" ";
    cout<<endl;
    
    
   
    int l=n/2;
    int r=(n-n/2);
    ll res1=0,res2=0;
    for(i=1;i<=l;i++)
        res1+=(fact[i]*val[l][i])%div;

    for(i=1;i<=r;i++)
    {
        res2+=(fact[i]*val[r][i])%div;
    }
    
    cout<<res1+res2<<endl;
        
    
    
}



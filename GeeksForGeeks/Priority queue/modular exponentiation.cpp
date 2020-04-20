#include<bits/stdc++.h>
using namespace std;
//get a^b%c
long long int getModularExpo(int a,int b,int c)
{
	a=a%c;
	long long int res=1;
	
	while(b>0)
	{
		if(b&1)//if b is odd
		res=(res*a)%c;	
		
		a=(a*a)%c;
		b=b/2; // b=b/2
	}
	
	return res;
		
		
}

int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	cout<<getModularExpo(a,b,c)<<endl;
	return 0;
}


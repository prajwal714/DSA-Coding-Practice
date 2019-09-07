#include<bits/stdc++.h>
using namespace std;

long long int fib(int a,int b,int lim)
{
	long long int sum=0;
	int c=a+b;
	
	while(c<lim)
	{
		
		a=b;
		b=c;
		cout<<c<<endl;
	if(c%2==0)
	sum+=c;
	c=a+b;
		
	}
	return sum;
}


int main()
{
	int lim;
	cin>>lim;
	cout<<fib(0,1,lim);
}

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,max;
	cin>>a>>b>>max;
	max--;
	int n1=max/a;
	int n2=max/b;
	int n3=max/(a*b);
	
	long long int sum=0;
	sum+=(n1*(n1+1)/2)*a+(n2*(n2+1)/2)*b-(n3*(n3+1)/2)*(a*b);
	
	cout<<sum<<endl;
}

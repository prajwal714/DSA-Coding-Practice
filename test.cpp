#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	 cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		long long int a,b;
		cin>>a>>b;
	long long count=0;
	for(int i=a;i<=b;i++)
	{
		count+=__builtin_popcount(i);
	}
	cout<<count<<endl;

	}
}

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
	int n;
	cin>>n;
	vector<int> arr(n);
	
	int i;
	for(i=0;i<n;i++)
	cin>>arr[i];
	
	int count=0;
	for(i=0;i<n;i++)
	{
	    if(arr[i]!=0)
	    arr[count++]=arr[i];
	}
	
	while(count<n)
	arr[count++]=0;

    for(int v:arr)
    cout<<v<<" ";
    cout<<endl;
	    
	}
	
	
	
	return 0;
}

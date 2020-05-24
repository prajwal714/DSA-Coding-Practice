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
	   int n,k;
	   cin>>n>>k;
	   
	   deque<int> dq(k);
	   vector<int> arr(n);
	   int i;
	   
	   for(i=0;i<n;i++)
	   cin>>arr[i];
	   
	   for(i=0;i<k;i++)
	   {
	       while(!dq.empty()&&arr[dq.back()]<=arr[i])
	       dq.pop_back();
	       
	       dq.push_back(i);
	   }
	   
	   for(;i<n;i++)
	   {
	       cout<<arr[dq.front()]<<" ";
	       
	       while(!dq.empty()&&dq.front()<=i-k)
	       dq.pop_front();
	       
	       while(!dq.empty()&&arr[dq.back()]<=arr[i])
	       dq.pop_back();
	       
	       dq.push_back(i);
	   }
	   
	   cout<<arr[dq.front()]<<" ";
	   cout<<endl;
	   
	   
	}
	return 0;
}

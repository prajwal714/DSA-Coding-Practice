#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
 {
     
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
         
         for(i=0;i<n-1;i+=2)
         {
             swap(arr[i],arr[i+1]);
         }
         
         for(int v:arr)
         cout<<v<<" ";
         cout<<endl;
     }
	//code
	return 0;
}

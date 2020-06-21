#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int k;
bool compare(int a, int b )
{
    return abs(a-k)<abs(b-k);
}

int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n;
         cin>>n>>k;
         
         vector<int> arr(n);
         int i;
         for(i=0;i<n;i++)
         cin>>arr[i];
         
        stable_sort(arr.begin(),arr.end(), compare);
         
         for(i=0;i<n;i++)
         cout<<arr[i]<<" ";
         
         cout<<endl;
     }
	//code
	return 0;
}

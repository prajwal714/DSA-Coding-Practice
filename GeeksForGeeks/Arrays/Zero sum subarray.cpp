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
         int arr[n];
         int i;
         for(i=0;i<n;i++)
         {
             cin>>arr[i];
         }
         
         unordered_map<int,int> ump;
         int count=0;
         int sum=0;
         ump[0]++;
         for(i=0;i<n;i++)
         {
             sum+=arr[i];
             
             if(ump.find(sum)!=ump.end())
             {
                 count+=ump[sum];
             }
             
             ump[sum]++;
         }
         
         cout<<count<<endl;
         
     }
	//code
	return 0;
}

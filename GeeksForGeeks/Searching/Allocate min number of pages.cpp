#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isValid(long long int arr[],int n, int k, long long int mid)
{
    int students=1;
    long long int sum=0;
    
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        
        if(sum>mid)
        {
            students++;
            sum=arr[i];
        }
        
        if(students>k)
        return false;
    }
    return true;
}

int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n;
         cin>>n;
         
         long long int arr[n];
         int i;
         for(i=0;i<n;i++)
         cin>>arr[i];
         
         int k;
         cin>>k;
         
         if(k>n)
         {
             cout<<-1<<endl;
             continue;
         }
         
         
         
         long long int start=-1;
         long long int end=0;
         long long int sum;
         for(i=0;i<n;i++)
         {
             start=max(start,arr[i]);
             end+=arr[i];
         }
         sum=end;
         long long int res=-1;
         
         if(k==1)
         {
             cout<<sum<<endl;
             continue;
         }
         while(start<=end)
         {
             long long int mid=start+(end-start)/2;
             
             if(isValid(arr,n,k,mid)==true)
             {
                 res=mid;
                 end=mid-1;
             }
             else
             {
                 start=mid+1;
             }
         }
         
         cout<<res<<endl;
     }
	//code
	return 0;
}

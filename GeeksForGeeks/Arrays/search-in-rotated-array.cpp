#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int getPivot(int arr[], int low, int high)
{
    
    if(high<low)
    return -1;
    
    
    if(low==high)
    return low;
    
    int mid=(high-low)/2+low;
    
    if(mid<high && arr[mid]>arr[mid+1])
    return mid;
    
    if(mid>low && arr[mid]<arr[mid-1])
    return mid-1;
    
    if(arr[mid]>arr[high])
    getPivot(arr,mid+1,high);
    else
    getPivot(arr,low,mid-1);
    
}

int binarySearch(int arr[], int key, int low, int high)
{
    if(high<low)
    return -1;
    
    int mid=(high-low)/2 +low;
    
    if(arr[mid]==key)
    return mid;
    
    else if(key<arr[mid])
    binarySearch(arr,key,low,mid-1);
    
    else if(key>arr[mid])
    binarySearch(arr,key,mid+1,high);
    
}


int main()
 {
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        
        int i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        int key;
        cin>>key;
        int pivot=getPivot(arr,0,n-1);
        int res;
        res=binarySearch(arr,key,0,pivot);
        
        if(res==-1)
        {
            res=binarySearch(arr,key,pivot+1,n-1);
        }
        
        cout<<res<<endl;
        
        
    }
	//code
	return 0;
}

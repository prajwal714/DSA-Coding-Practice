#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int get_majority_elem(int arr[], int n)
{
    int maj_elem=arr[0];
        int count=1;
        
        for(int i=1;i<n;i++)
        {
            if(arr[i]==maj_elem)
            count++;
            else
            count--;
            
            if(count==0)
            {
            maj_elem=arr[i];
            count=1;                
            }
        }
        
        return maj_elem;
}

int isMajorityElem(int arr[], int n, int elem)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==elem)
        count++;
    }
    
    if(count>(n/2))
    return elem;
    else
    return -1;
}


int main()
 {
    IOS;
    //here we will be using Moore's voting algorithm
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
        
        int candidate=get_majority_elem(arr, n);
        
        cout<<isMajorityElem(arr,n,candidate)<<endl;
        
        
    }
	//code
	return 0;
}

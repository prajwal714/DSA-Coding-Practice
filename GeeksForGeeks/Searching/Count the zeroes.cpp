#include<iostream>
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
	    int arr[n];
	    
	    int i;
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    
	    int ele=1;
	    int start=0, end=n-1;
	    int lastOcc=-1;
	    while(start<=end)
	    {
	        int mid=start+(end-start)/2;
	        
	        if(arr[mid]==ele)
	        {
	            lastOcc=mid;
	            start=mid+1;
	        }
	        else if(ele<arr[mid])
	        {
	            start=mid+1;
	        }
	        else
	        end=mid-1;
	    }
	    
	    cout<<n-(lastOcc+1)<<endl;
	}
	return 0;
}

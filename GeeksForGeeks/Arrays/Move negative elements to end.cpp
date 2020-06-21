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
	    
	    for(i=1;i<n;i++)
	    {
	        if(arr[i]<0)
	        continue;
	        
	        int key=arr[i];
	        int j=i-1;
	        
	        while(j>=0&&arr[j]<0)
	        {
	            arr[j+1]=arr[j];
	            j--;
	        }
	        
	        arr[j+1]=key;
	    }
	    
	    for(i=0;i<n;i++)
	    cout<<arr[i]<<" ";
	    cout<<endl;
	}
	return 0;
}

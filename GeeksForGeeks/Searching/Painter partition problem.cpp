#include<iostream>
using namespace std;

bool isValid(int arr[], int n, int k, int mid)
{
    int painter=1;
    int sum=0;
    
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum>mid)
        {
            sum=arr[i];
            painter++;
        }
        
        if(painter>k)
        return false;
    }
    
    return true;
}

int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int k,n;
	    cin>>k>>n;
	    int arr[n];
	    int i;
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    
	    if(k>n)
	    {
	       k=n;
	    }
	    
	    int start=-1;
	    int end=0;
	    for(i=0;i<n;i++)
	    {
	        start=max(start,arr[i]);
	        end+=arr[i];
	    }
	    
	    if(k==1)
	    {
	        cout<<end<<endl;
	        continue;
	    }
	    
	    //=============================================================
	    int res=-1;
	    while(start<=end)
	    {
	        int mid=start+(end-start)/2;
	        
	        if(isValid(arr,n,k,mid)==true)
	        {
	            res=mid;
	            end=mid-1;
	        }
	        else
	        start=mid+1;
	    }
	    
	    cout<<res<<endl;
	}
	return 0;
}

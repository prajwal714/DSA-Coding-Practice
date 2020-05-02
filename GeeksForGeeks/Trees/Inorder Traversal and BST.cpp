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
	    int flag=1;
	    for(i=0;i<n-1;i++)
	    {
	        //the array is not strictly increasing then its not inorder traversal of BST
	        if(arr[i]>=arr[i+1])
	        {
	            flag=0;
	            break;
	        }
	    }
	    cout<<flag<<endl;
	}
	return 0;
}

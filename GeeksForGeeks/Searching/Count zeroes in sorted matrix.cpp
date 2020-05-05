// { Driver Code Starts
#include <iostream>
using namespace std;
#define MAX 1000
int countZeroes(int A[MAX][MAX],int N);

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int A[MAX][MAX];
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		cin>>A[i][j];
		cout<<countZeroes(A,n)<<endl;
	}
	return 0;
}// } Driver Code Ends

int lastOcc(int A[MAX][MAX], int row, int N)
{
    int start=0, end=N-1;
    int res=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        
        if(A[row][mid]==0)
        {
            res=mid;
            start=mid+1;
        }
        
        else if(0<A[row][mid])
        {
            end=mid-1;
        }
        else
        start=mid+1;
        
        
    }
    
    return res;
}
int firstOcc(int A[MAX][MAX], int row, int N)
{
   
    int start=0, end=N-1;
    int res=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        
        if(A[row][mid]==0)
        {
            res=mid;
           end=mid-1;
        }
        
        else if(0<A[row][mid])
        {
           end=mid-1;
        }
        else
        start=mid+1;
        
        
    }
    
    return res;
    
}


/*you are required to complete this method*/
int countZeroes(int A[MAX][MAX],int N)
{
    int count=0,i;
    for(i=0;i<N;i++)
    {
        if(firstOcc(A,i,N)!=-1)
        count+=(lastOcc(A,i,N)-firstOcc(A, i, N))+1;
    }
    return count;
//Your code here
}


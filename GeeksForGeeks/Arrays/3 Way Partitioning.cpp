// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<int> threeWayPartition(vector<int> A,
                   int lowVal, int highVal);

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	
		int N;
		cin>>N;
		vector<int> A(N);
		int hash[1000001];
		memset(hash,0,sizeof hash);
		
		for(int i=0;i<N;i++){
		cin>>A[i];
		hash[A[i]]++;
		}
		
		int n,m;
		cin>>n>>m;
		
		// vector to store the answer
		// to verify the correct output
		vector<int> B(A.size());
		for(int i=0;i<A.size();i++)
		{
			B[i]=A[i];
		}

        int k1=0,k2=0,k3=0;
        int kk1=0;int kk2=0;int kk3=0;
        
        for(int i=0;i<B.size();i++)
        {
            
        	if(B[i]>m)
        	{
        		k3++;
        	}
        	else if(B[i]<=m and B[i]>=n)
        	{
        		k2++;
        	}
        	else if(B[i]<m)
        	k1++;
        }
        
		vector<int> Res = threeWayPartition(A,
                n,m);
      
      	for(int i=0;i<k1;i++)
      	{
      		if(Res[i]<m)
      		kk1++;
      	}
      	
      	for(int i=k1;i<k1+k2;i++)
      	{
      		
      		if(Res[i]<=m and Res[i]>=n)
      		kk2++;
      		
      	}
      	
      	for(int i=k1+k2;i<k1+k2+k3;i++)
      	{
      		if(Res[i]>m)
      		kk3++;
      	}
      	bool ok = 0;
      	if(k1==kk1 and k2 ==kk2 and k3 == kk3)
      	ok = 1;
	    for(int i=0;i<Res.size();i++)
      		hash[Res[i]]--;
      	
      	for(int i=0;i<Res.size();i++)
      	if(hash[Res[i]]!=0)
      	ok=0;
      	
		if(ok)
		cout<<1<<endl;
		else
		cout<<0<<endl;
		
	}
	
	return 0;
}// } Driver Code Ends


/*The function should return the modified array
as specified in the problem statement */

//Also Variation of Dutch national flag problem, sort array of 0,1,2 numbers etc.
vector<int> threeWayPartition(vector<int> A, int a, int b)
{
    int low=0,mid=0,high=A.size()-1;
    
    while(mid<=high)
    {
        if(A[mid]<a)
        {
            swap(A[mid],A[low]);
            low++;
            mid++;
        }
        else if(A[mid]>b)
        {
            swap(A[mid],A[high]);
            high--;
           
        }
        else mid++;
    }
    
    return A;
     //Your code here
}


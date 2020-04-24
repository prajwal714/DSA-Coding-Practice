#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int main()
 {
    IOS;
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int k,row,col;
	    cin>>k>>row>>col;
	    
	        //If the water in last row is beyond capacity overflow it too...that is why we took row+1 rows of glasses
	    double arr[row+1][row+1];
	   
	    
	    int i,j;
	    memset(arr, 0, sizeof(arr));
	    arr[0][0]=k;
	    for(i=0;i<row;i++)
	    {
	        for(j=0;j<=i;j++)
	        {
	            double cap=arr[i][j];
	            
	            if(arr[i][j]>1)
	            {
	                arr[i][j]=1;
	                
	            }
	           double overflow;
	           if(cap>1)
	           {
	               overflow=cap-1;
	           }
	           else
	           overflow=0;
	           
	           
	            arr[i+1][j]+=overflow/2;
	            arr[i+1][j+1]+=overflow/2;
	            
	            
	         
	            
	        }
	            
	       }
	       // for(i=0;i<row;i++)
	       // {
	       //     for(j=0;j<=i;j++)
	       //     cout<<arr[i][j]<<" ";
	            
	       //     cout<<endl;
	       // }
	       cout<<arr[row-1][col-1]<<endl;
	    }
	
	return 0;
}
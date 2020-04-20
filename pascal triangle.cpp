#include<bits/stdc++.h>
using namespace std;

int main()
{
	int row;
    cout<<"Enter Number of Row: "<<endl;
	cin>>row;
	
	int arr[row][row];
    
    
    

    int i,j;

    for(i=0;i<row;i++)
    {
        for(j=0;j<=i;j++)
        {
            if(i==j || j==0)
            arr[i][j]=1;
           
        }
    }
    for(i=1;i<row;i++)
    {
        for(j=1;j<i;j++)
        {
            arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
        }
    }

     for(i=0;i<row;i++)
    {
        for(j=0;j<=i;j++)
        {
           cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }



}



// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool isInterleave(string A, string B, string C);
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		cout<<isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}// } Driver Code Ends


/*You are required to complete this method */
bool LCS(string A, string B, string C)
{
    int m=A.length(), n=B.length();
    
    if((m+n)!=C.length())
    return false;
    
    
    bool t[m+1][n+1];
    memset(t, false, sizeof(t));
    int i,j;
    
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0&&j==0)
            t[i][j]=true;
            
            else if(i==0)
            {
                if(B[j-1]==C[j-1])
                t[i][j]=t[i][j-1];
            }
            else if(j==0)
            {
                if(A[i-1]==C[i-1])
                t[i][j]=t[i-1][j];
            }
            else if(A[i-1]==C[i+j-1]&&B[j-1]!=C[i+j-1])
            t[i][j]=t[i-1][j];
            
            else if(A[i-1]!=C[i+j-1]&&B[j-1]==C[i+j-1])
            t[i][j]=t[i][j-1];
            
            else if(A[i-1]==C[i+j-1]&&B[j-1]==C[i+j-1])
            t[i][j]=t[i-1][j]||t[i][j-1];
        }
    }
    
    return(t[m][n]);
}

bool isInterleave(string A, string B, string C) 
{
    
   return LCS(A,B,C);
    //Your code here
}


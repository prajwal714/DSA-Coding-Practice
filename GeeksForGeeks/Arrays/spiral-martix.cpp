#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int arr[10][10];

vector<int> spiralMatrix(int m, int n)
{
    int dir=0;
    int top=0, down=m-1, left=0, right=n-1;
    vector<int> res;
    int i;
    while(top<=down && left<=right)
    {
        if(dir==0)
        {
            for(i=left;i<=right;i++)
            {
                res.push_back(arr[top][i]);
                
            }
            top++;
        }
        
        else if(dir==1)
        {
            for(i=top;i<=down;i++)
            {
                res.push_back(arr[i][right]);
            }
            right--;
        }
        
        else if(dir==2)
        {
            for(i=right;i>=left;i--)
            {
                res.push_back(arr[down][i]);
            }
            down--;
        }
        else if(dir==3)
        {
            for(i=down;i>=top;i--)
            {
                res.push_back(arr[i][left]);
            }
            left++;
            
        }
        
        dir=(dir+1)%4;
        
    }
    
    return res;
    
    
}




int main()
 {
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        
        
        
        int i,j;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            cin>>arr[i][j];
        }
        
        vector<int> res=spiralMatrix( m,n);
        for(int v: res)
        cout<<v<<" ";
        
        cout<<endl;
        
    }
	//code
	return 0;
}

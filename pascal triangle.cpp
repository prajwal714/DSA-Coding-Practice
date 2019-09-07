#include<bits/stdc++.h>
using namespace std;

int main()
{
	int row;
	cin>>row;
	
	vector<vector<int>> arr(row);
    arr[0].push_back(1);
    
    int i;
    for(i=1;i<row;i++)
    {
        arr[i].push_back(1);
        for(int j=1;j<i+1;j++)
        {
            if(j==i)
            arr[i].push_back(1);
            else
            arr[i].push_back(arr[i-1][j]+arr[i-1][j-1]);
        }
    }
    for(i=0;i<row)
}



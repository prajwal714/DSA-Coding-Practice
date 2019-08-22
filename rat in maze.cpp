#include<bits/stdc++.h>
using namespace std;
# define R 5
#define C 5
bool isSafe(int matrix[R][C],int x,int y)
{
	if((x>=0&&x<R)&&(y<C&&y>=0)&&matrix[x][y]==1)
	return true;
	else
	return false;
}

bool solveUtil(int matrix[R][C],int x,int y,int sol[R][C])
{
	if(matrix[x][y]==9)
	{
		sol[x][y]=1;
		return true;
	}
	
	
	if(isSafe(matrix,x,y)==true)
	{
		sol[x][y]=1;
		
		if(solveUtil(matrix,x+1,y,sol)==true)
		return true;
		
		if(solveUtil(matrix,x,y+1,sol)==true)
		return true;
		
		sol[x][y]=0;
		return false;
		}
		
		return false;
}
void display(int matrix[R][C])
{
	int i,j;
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}
int solveMaze(int matrix[R][C])
{
	int sol[R][C]={{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0}};
	
		
	if(solveUtil(matrix,0,0,sol)==true)
	{
	
		cout<<"True";
	}
	
	else
	cout<<"False";
	display(sol);
}


int main()
{
	int row,col;
	row=5; col=5;
	int matrix[][C]={{1,0,0,1,1},
						{1,0,1,0,1},
						{1,1,0,0,9},
						{0,1,1,0,1},
						{0,0,1,1,1}};
			
	cout<<solveMaze(matrix);			
	return 0;
}

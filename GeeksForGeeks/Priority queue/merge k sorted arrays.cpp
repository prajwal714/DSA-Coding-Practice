
#include<bits/stdc++.h>
#define N 100
using namespace std;
int *mergeKArrays(int arr[][N],int k);
void printArray(int arr[], int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}
int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    int arr[N][N];
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	int *output = mergeKArrays(arr, k);
	printArray(output, k*k);
	cout<<endl;
}
	return 0;
}

/*This is a function problem.You only need to complete the function given below*/
// your task is tocomplete this function
// function should return an pointer to output array int*
// of size k*k

struct compare{
    bool operator()(pair<int,int> a,pair<int,int> b)
    {
        return a.first>=b.first;
    }
};


int *mergeKArrays(int arr[][N], int k)
{
   priority_queue<pair<int,int> , vector<pair<int,int>>, compare> pq;
   int* res=(int*)malloc(sizeof(int)*k*k);
   int i;
   for(i=0;i<k;i++)
   {
       pq.push(make_pair(arr[i][0],i));
   }
   vector<int> col(k,0);
   int index=0;//to store the front of every k row, if an element from row if popped we increment the row[k]
   for(i=0;i<k*k;i++)
   {
       int elem=pq.top().first;
       int row=pq.top().second;
      
       res[index++]=elem;
       pq.pop();
       if(col[row]<k-1)
       {
       col[row]++;
       pq.push(make_pair(arr[row][col[row]],row));
           
       }
       
    }

   return res;
   
}

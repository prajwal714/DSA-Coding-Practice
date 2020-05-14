int findPivot(vector<int> arr, int low, int high)
{
    if(low>high)
    return -1;
    
    int mid=(high+low)/2;
   
   if(mid<high && arr[mid]>arr[mid+1])
   return mid;
   
   if(mid>low&&arr[mid]<arr[mid-1])
   return mid-1;
   
   if(arr[low]>arr[mid])
   return findPivot(arr,low,mid-1);
  
   return findPivot(arr,mid+1,high);
}
int binSearch(vector<int> arr, int low, int high, int key)
{
    if(low>high)
    return -1;
    
    int mid=(high+low)/2;
    
    if(arr[mid]==key)
    return mid;
    
    else if(arr[mid]<key)
    binSearch(arr,mid+1,high,key);
    
    else
    binSearch(arr,low,mid-1,key);
}

int Solution::search(const vector<int> &A, int B) {
    
   int min=0,max=0;

for(int i=1;i<A.size();i++)
{
    if(A[i]>=A[max])
    {
        max=i;
    }
    else
    {
        break;
    }
}

if(B<A[min])
{
    min=max+1;
    max=A.size()-1;
}

while(min<=max)
{
    int mid=(min+max)/2;
    
    if(A[mid]==B)
    {
        return mid;
    }
    
    if(A[mid]>B)
    {
        max=mid-1;
    }
    else
    {
        min=mid+1;
    }
}

return -1;
    
}
========================================================================================================
int Solution::search(const vector<int> &A, int B) {
    int n = A.size();
    int low = 0, high = n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(A[mid] == B) return mid;
        else if(A[0]<=A[mid]){//i.e. left part is sorted
            if(A[0]<=B && B < A[mid]) high = mid-1;//B lies on left part
            else low = mid+1;
        }else{//right part is sorted
            if(A[mid] < B && B<=A[n-1]) low = mid+1;//B lies on right part
            else high = mid-1;
        }
    }
    return -1;
}

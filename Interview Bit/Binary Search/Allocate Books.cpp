bool isValid(vector<int> A, int maxStud, int mid)
{
    int i;
    int students=1;
    long long int sum=0;
    for(i=0;i<A.size();i++)
    {
        sum+=A[i];
        if(sum>mid)
        {
            students++;
            sum=A[i];
        }
        
        if(students>maxStud)
        return false;
    }
    
    return true;
}

int Solution::books(vector<int> &A, int B) {
    
    if(B>A.size())
    return -1;
    
    int start=INT_MIN;
    long long int end=0, res;
    int i;
    for(i=0;i<A.size();i++)
    {
        start=max(start,A[i]);
        end+=A[i];
    }
    
    while(start<=end)
    {
        long long int mid=start+(end-start)/2;
        
        if(isValid(A,B,mid)==true)
        {
        res=mid;            
        end=mid-1;
        }
        else
        start=mid+1;
    }
    
    return res;
}


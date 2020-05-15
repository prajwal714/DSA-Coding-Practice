bool isValid(vector<int> C, int max_painters, int mid)
{
    int painter=1;
    long long int sum=0;
    
    for(int i=0;i<C.size();i++)
    {
        sum+=C[i];
        if(sum>mid)
        {
            sum=C[i];
            painter++;
        }
        
        if(painter>max_painters)
        return false;
    }
    return true;
}

int Solution::paint(int A, int B, vector<int> &C) {
    
    int n=C.size();
    if(A>n)
    A=n;
    
    int start=-1;
    long long int end=0;
    
    int i;
    for(i=0;i<n;i++)
    {
        start=max(start,C[i]);
        end+=C[i];
    }
    long long int res=-1;
    while(start<=end)
    {
        long long int mid=start+(end-start)/2;
        
        if(isValid(C,A,mid)==true)
        {
            res=mid;
            end=mid-1;
        }
        else
        start=mid+1;
    }
    
    return (int)((res*B)%10000003);
    
    
}


vector<int> Solution::plusOne(vector<int> &arr) {
    int i;
    int n=arr.size();
    int carry=1;
    vector<int> res(n+1,0);
    for(i=n;i>=1;i--)
    {
        int num=arr[i-1];
        res[i]=(num+carry)%10;
        carry=(num+carry)/10;
        
    }
    if(carry!=0)
    {
        
        
        res[0]=carry;
        
        
        
    }
    int inx;
    for(i=0;i<=n;i++)
    {
        if(res[i]!=0)
        {
            inx=i;
            break;
        }
    }
    vector<int> br(n+1-inx);
    for(i=0;i<=n-inx;i++)
    {
        br[i]=res[i+inx];
    }
    return br;
}

int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    
    int x=0,y=0,z=0;
    int a,b,c;
    int res=INT_MAX;
    while(x<A.size()&&y<B.size()&&z<C.size())
    {
        a=A[x]; b=B[y]; c=C[z];
        
        res=min(res,max(a,max(b,c))-min(a,min(b,c)));
        
       if(a<=b&&a<=c)
       x++;
       else if(b<=a && b<=c)
       y++;
       else if(c<=a&&c<=b)
       z++;
       
       
    }
    
    return res;
}


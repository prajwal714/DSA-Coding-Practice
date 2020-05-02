 int Solution::firstMissingPositive(vector<int> &A) {
        int n=A.size();
        vector<bool> v(n+2,false);
        int k=0;
        for(int i=0;i<A.size();i++)
        {
            if(A[i]>0&&A[i]<=n)
            {
         
            v[A[i]]=true;
        }
        
    }
    for(int i=1;i<v.size();i++)
    {
        if(v[i]==false)
        {
            return i;
            
        }
    }
}

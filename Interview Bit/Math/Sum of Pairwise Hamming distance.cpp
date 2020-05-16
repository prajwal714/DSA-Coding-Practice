int Solution::hammingDistance(const vector<int> &A) {
    
    vector<int> bin_array(32,0);
    const int mod=1000000007;
    int i;
    for(i=0;i<A.size();i++)
    {
        int index=0;
        int num=A[i];
        while(num>0)
        {
            bin_array[index]+=(num&1);
           num=num>>1;
            index++;
        }
    }
    int ans=0;
    for(i=0;i<32;i++)
    {
        ans=(ans+((bin_array[i])*(A.size()-bin_array[i])*2))%mod;
    }
    
    return ans;
}


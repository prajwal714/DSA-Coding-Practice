int Solution::titleToNumber(string A) {
    
    int res=0;
    int i;
    int k=0;
    for(i=A.length()-1;i>=0;i--)
    {
        res+=pow(26,k)*(A[i]-'A'+1);
        k++;
    }
    
    return res;
}


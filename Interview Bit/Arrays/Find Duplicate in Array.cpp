int Solution::repeatedNumber(const vector<int> &A) {
    
    vector<int> B=A;
    
    for(int i=0;i<B.size();i++)
    {
        if(B[abs(B[i])]<0)
        return abs(B[i]);
        
        else
        B[abs(B[i])]*=-1;
    }
    
    return -1;
    
}


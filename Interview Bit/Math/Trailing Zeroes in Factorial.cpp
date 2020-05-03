int Solution::trailingZeroes(int A) {
    int num5=0;
    int num2=0;
    
    int k=1;
    
    int B=A;
    while((B/pow(5,k)))
    {
        num5+=(B/pow(5,k));
        k++;
    }
    
    B=A;
    k=1;
    while((B/pow(2,k)))
    {
        num2+=(B/pow(2,k));
        k++;
    }
    
    return min(num5,num2);
    
}

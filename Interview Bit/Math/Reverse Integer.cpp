int Solution::reverse(int A) {
    
    if(A==0)
    return 0;
    
    int rev=0;
    bool neg=false;
    int num=A;
    
        if(num<0)
        {
            neg=true;
            num=-num;
        }
    
    
  
   
    while(num!=0)
    {
        int currDigit=num%10;
        if(rev>(INT_MAX-currDigit)/10)
        {
            return 0;
        }
        else
        rev=rev*10+currDigit;
        
       
        
       
        num=num/10;
        
    }
    
    if(neg)
    {
        rev=rev*-1;
        if(rev>0)
        return 0;
        else
        return rev;
    }
    else
    return rev;

       
   
    
}


class Solution {
public:
    double myPow(double x, int n) {
        
        if(x==1)
            return 1;
        
        if(n==0)
            return 1;
        if(n<0)
        {
            if(n==INT_MIN) //this is to handle the case t avoid overflow of INT_MIN on -ve to +ve
                n+=2;
            
            n=-n;
            x=1/x;
            return myPow(x,n);
        }
        
        if(n%2==0)
            return myPow(x*x, n/2);
        else
            return x*myPow(x*x, n/2);
    }
};
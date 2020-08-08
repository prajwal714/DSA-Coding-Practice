//9=1001
//x^9=x^(2^3)*x^(2^0);

class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        long absN=abs((long)n);
        
        while(absN>0)
        {
            if((absN&1)==1)
                ans=ans*x;
            
            absN=absN>>1;
            x=x*x;
        }
        
        return (n<0)? 1/ans:ans; 
    }
};
class Solution {
public:
    int sumOfSq(int n)
    {
        int sum=0;
        while(n!=0)
        {
            int rem=n%10;
            sum+=rem*rem;
            n/=10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        
       int slow=n,fast=n;
        do{
            slow=sumOfSq(slow);
            fast=sumOfSq(fast);
            fast=sumOfSq(fast);
            
            
        }
        while(slow!=fast);
        
        return(slow==1);
       
    }
};
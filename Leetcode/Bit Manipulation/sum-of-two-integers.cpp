class Solution {
public:
    int getSum(int a, int b) {
        
        int c;
        while(b!=0)
        {
            c=a&b; //calculates the carry
            a=a^b; //calculates the sum without carry
            b=unsigned(c)<<1; //creates a new b to be added to a, carry left shifted to 1 value
        }
        
        return a;
    }
};
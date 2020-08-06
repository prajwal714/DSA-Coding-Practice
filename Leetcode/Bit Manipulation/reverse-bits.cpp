//we create an unsigned mask of 32 bits, we check the last bit of n 

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t mask=1<<31;
        int res=0;
        
        for(int i=0;i<32;i++)
        {
            if(n&1) //check the last bit of n
            {
                res=res|mask; //if lat bit is 1, we OR it with our Mask to create a reverse
            }
            
            mask=mask>>1; //right shift both mask and nnumber
            n=n>>1;
        }
        
        return res;
        
    }
};
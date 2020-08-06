class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        
        while(n)
        {
            n=n&(n-1); //returns the last set bit
            count++;
        }
        
        return count;
    }
};

//10011-> 1001 -> 1 hence count=3;
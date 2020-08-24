class Solution {
public:
    int trailingZeroes(int n) {
        
        int num=n;
        
        int k=1;
        int count=0;
        while(num/pow(5,k))
        {
            count+=(num/pow(5,k));
            k++;
        }
        
        return count;
        
        
    }
};
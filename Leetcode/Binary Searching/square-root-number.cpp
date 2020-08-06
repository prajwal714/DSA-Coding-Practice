class Solution {
public:
    int mySqrt(int x) {
        
        if(x==1)
            return x;
        
        int low=1, high=x-1;
        
        int res=0;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            if(mid<=x/mid)
            {
                res=mid;
                low=mid+1;
            }
            else
                high=mid-1;
            
                
        }
        
        return res;
    }
};
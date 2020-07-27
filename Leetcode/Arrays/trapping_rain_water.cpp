
//O(n) space and time complexity
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n==0)
            return 0;
        
        vector<int> lmax(n), rmax(n);
        
        int i;
        lmax[0]=height[0];
        for(i=1;i<n;i++)
        {
            lmax[i]=max(lmax[i-1], height[i]);
            
        }
        
        rmax[n-1]=height[n-1];
        for(i=n-2;i>=0;i--)
        {
            rmax[i]=max(rmax[i+1], height[i]);
        }
        int water=0;
        for(i=0;i<n;i++)
        {
            water+=min(rmax[i], lmax[i])-height[i];
        }
        
        return water;
    }
};

//space optimized solution
//O(n) time and O(1) space complexity using two pointer approacvh for left and right max

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n==0)
            return 0;
      
        int water=0;
        
        int lmax=0,rmax=0;
        int left=0,right=n-1;
        
        while(left<right)
        {
            
             if(height[left]>lmax)
                    lmax=height[left];
            
              if(height[right]>rmax)
                    rmax=height[right];
            
            if(height[left]<=height[right])
            {
               
                
                water+=lmax-height[left];
                left++;
            }
            else
            {
              
                
                water+=rmax-height[right];
                right--;
            }
        }
        
        return water;
      
    }
};

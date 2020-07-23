class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int n=nums.size();
        
       int minElem=INT_MAX, maxElem=INT_MIN;
        int i;
        bool flag=false;
        for(i=1;i<n;i++)
        {
            if(nums[i]<nums[i-1])
                flag=true;
            
            if(flag==true)
            {
                minElem=min(minElem, nums[i]);
            }
        }
        
        flag=false;
        
        for(i=n-2;i>=0;i--)
        {
            if(nums[i]>nums[i+1])
                flag=true;
            
            if(flag)
            {
                maxElem=max(maxElem, nums[i]);
            }
        }
        
        int l,r;
        for(l=0;l<n;l++)
        {
            if(minElem<nums[l])
                break;
        }
        
        for(r=n-1;r>=0;r--)
        {
            if(maxElem>nums[r])
                break;
        }
        
        if((r-l)<=0)
            return 0;
        else
            return r-l+1;
        
        
        
    }
};

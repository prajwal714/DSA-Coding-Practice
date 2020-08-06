class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int n=nums.size();
        int low=0,high=n-1;
        
        int res;
        while(low<high)
        {
            int mid=(low+high)/2;
            
           if(nums[mid]>nums[mid+1])
           {
               high=mid;
           }
            else
            {
                low=mid+1;
            }
        }
        return low;
        
    }
    
};
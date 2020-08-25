
//we know the answer lies between 1 and n+1 inclusive, 
// complexity O(n) and O(1)

/* so we simply swap the numbers with their correct correct position numbers, such that i+1=nums[i] for each i
in case nums[i]<0 || nums[i]>n we simply ignore these values

the smallest i where i+1 != nums[i] is our answer
 */

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       
      int n=nums.size();
        if(n==0)
            return 1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<0 || nums[i]>n)
                continue;
                
            int pos=nums[i]-1;
            
            while(nums[i]>=1 && nums[i]<=n && nums[i]!=nums[pos])
            {
                swap(nums[i], nums[pos]);
                pos=nums[i]-1;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=i+1)
            {
                return i+1;
            }
                
        }
        
        return n+1;
        
    }
};
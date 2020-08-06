/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int binSearch(MountainArray &nums, int low, int high, int target, bool dec)
    {
        while(low<=high)
        {
            int mid=(low+high)/2;
            int midElem=nums.get(mid);
            if(midElem==target)
                return mid;
            else if(midElem<target)
            {
                if(dec==false)
                low=mid+1;
                else
                high=mid-1;
                    
            }
            else
            {
                if(dec==false)
                    high=mid-1;
                else
                    low=mid+1;
            }
        }
        return -1;
    }
    
    int findInMountainArray(int target, MountainArray &nums) {
        
        int pivot;
        
        int n=nums.length();
        
        int low=0,high=n-1;
        while(low<high)
        {
            int mid=(low+high)/2;
            
            if(nums.get(mid)>nums.get(mid+1))
                high=mid;
            else
                low=mid+1;
        }
        //we find the index of peak element
        pivot=low;
        
        int leftLow,rightLow;
        //bin search in inc array
        leftLow=binSearch(nums, 0, pivot, target, false);
        //bin search in dec array
        rightLow=binSearch(nums, pivot, n-1, target, true);
        
        if(leftLow!=-1)
            return leftLow;
        else
            return rightLow;
        
        
        
    }
};
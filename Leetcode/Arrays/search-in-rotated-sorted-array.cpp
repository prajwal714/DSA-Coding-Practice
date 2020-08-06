class Solution {
public:
    int binSearch(vector<int> &nums, int start, int end, int target)
    {
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                start=mid+1;
            else
                end=mid-1;
        }
        
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        
        int pivot;
        int n=nums.size();
        if(n==0)
            return -1;
        
        int low=0,high=n-1;
        //Shortest code to find the position of min element
        while(low<high)
        {
            int mid=(low+high)/2;
            
            if(nums[mid]>nums[high])
                low=mid+1;
            else
                high=mid;
        }
        //low index points to the min element
        pivot=low;
        if(target==nums[pivot])
            return pivot;
        //we binary search in the left and right half of the pivot index
        int res=binSearch(nums, 0,pivot-1,target);
        
        if(res==-1)
            res=binSearch(nums, pivot+1, n-1, target);
        
        return res;
        
        
        
    }
};
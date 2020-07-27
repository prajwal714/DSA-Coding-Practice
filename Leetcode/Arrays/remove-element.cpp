class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int n=nums.size();
        int right=n;
        for(int left=0;left<right;)
        {
            if(nums[left]==val)
            {
                swap(nums[left], nums[right-1]);
                right--;
               
            }
            else
                left++;
        }
        
        return right;
    }
};

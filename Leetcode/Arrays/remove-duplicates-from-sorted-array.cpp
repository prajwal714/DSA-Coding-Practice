class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=0;
        int n=nums.size();
        if(n==0)
            return 0;
        
        //this can be generalized for atmost k duplicate elements, just replace 2 with k
        for(j=0;j<n;j++)
        {
            if(i<2||nums[j]>nums[i-2])
            {
                nums[i++]=nums[j];
            }
        }
        
        return i;
    }
};

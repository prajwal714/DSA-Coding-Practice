class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int i;
        
        for(i=1;i<n;i++)
        {
            if(nums[i-1]>0)
            {
                nums[i]+=nums[i-1];
            }
        }
        
        int res=INT_MIN;
        for(i=0;i<n;i++)
            res=max(res,nums[i]);
        
        return res;
    }
};

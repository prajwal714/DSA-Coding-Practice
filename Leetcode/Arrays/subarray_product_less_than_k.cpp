class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1)
            return 0;
        int n=nums.size();
        int prod=1,left=0, res=0;
        
        for(int right=0;right<n;right++ )
        {
            prod*=nums[right];
            
            while(prod>=k)
            {
                prod=prod/nums[left++];
            }
            
            res+=right-left+1;
        }
        
        return res;
    }
};

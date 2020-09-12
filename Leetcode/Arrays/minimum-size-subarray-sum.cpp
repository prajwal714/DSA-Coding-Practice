class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        if(nums.size()==0)
            return 0;
        
        int left=0,right=0;
        int sum=nums[0];
        int res=INT_MAX;
        while(left<=right)
        {
            while(sum<s && right+1<nums.size())
            {
                right++;
                sum+=nums[right];
            }
            
            if(sum>=s)
            {
                res=min(res, right-left+1);
            }
            
            sum-=nums[left];
            left++;
        }
        if(res==INT_MAX)
            return 0;
        
        return res;
    }
};

//complexity: O(n)
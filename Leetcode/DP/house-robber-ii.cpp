class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        
        vector<int> A(nums.begin(), nums.end()-1);
        vector<int> B(nums.begin()+1, nums.end());
        
        return max(robSum(A), robSum(B));
    }
    
    int robSum(vector<int> &nums)
    {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        int prevprev=0;
        int prev=0;
        int res;
        for(int i=0;i<nums.size();i++)
        {
            res=max(nums[i]+prevprev, prev);
            prevprev=prev;
            prev=res;
            
        }
        return res;
    }
};
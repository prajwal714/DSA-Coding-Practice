class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        vector<vector<int>> res;
        
        backtrack(res, vector<int>(),nums, target, 0);
        return res;
    }
    
    void backtrack(vector<vector<int>> &res, vector<int> temp, vector<int> nums, int target, int pos)
    {
        if(target==0)
        {
            res.push_back(temp);
            return;
        }
        
        for(int i=pos;i<nums.size();i++)
        {
            if(target<nums[i])
                continue;
            
            temp.push_back(nums[i]);
            
            backtrack(res, temp, nums, target-nums[i], i);
            
            temp.pop_back();
        }
    }
};
//this is similar to combinations, instead we have to use each number exactly once similar to 0-1 knapsack

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        backtrack(res, vector<int> (), nums, target, 0);
        
        return res;
    }
    
    void backtrack(vector<vector<int>> &res, vector<int> temp, vector<int> &nums, int target, int pos)
    {
        if(target<0)
            return;
        
        if(target==0)
        {
            res.push_back(temp);
            return;
        }
        
        for(int i=pos;i<nums.size();i++)
        {
            
            if(i>pos && nums[i]==nums[i-1])
                continue;
            
            temp.push_back(nums[i]);
            backtrack(res, temp, nums, target-nums[i], i+1);
            temp.pop_back();
        }
    }
};
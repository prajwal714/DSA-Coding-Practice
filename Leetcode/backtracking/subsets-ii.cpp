class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        backtrack(res, vector<int>(), 0, nums);
        
        return res;
    }
    
    void backtrack(vector<vector<int>> &res, vector<int> temp, int pos, vector<int> nums)
    {
        res.push_back(temp);
        
        for(int i=pos;i<nums.size();i++)
        {
            if(i>pos && nums[i]==nums[i-1])
                continue;
            
            temp.push_back(nums[i]);
            backtrack(res, temp, i+1, nums);
            temp.pop_back();
        }
        
        return;
    }
};
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> res;
        unordered_map<int,bool> used;
        sort(nums.begin(), nums.end());
        backtrack(res, vector<int> (), used, nums);
        
        return res;
    }
    
    void backtrack(vector<vector<int>> &res, vector<int> temp, unordered_map<int,bool> used, vector<int> &nums)
    {
        if(temp.size()==nums.size())
        {
            res.push_back(temp);
            return;
        }
        
        else
        {
            for(int i=0;i<nums.size();i++)
            {
                if(used[i] || (i>0 && nums[i]==nums[i-1] && !used[i-1]))
                    continue;
                
                used[i]=true;
                temp.push_back(nums[i]);
                backtrack(res, temp, used, nums);
                
                used[i]=false;
                temp.pop_back();
            }
        }
    }
};
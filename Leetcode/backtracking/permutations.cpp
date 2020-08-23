//this is for distinct elements in nums array, complexity: 

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        unordered_map<int,bool> mp;
        vector<vector<int>> res;
        backtrack(res, vector<int> (), mp, nums);
        
        return res;
    }
    
    void backtrack(vector<vector<int>> &res, vector<int> temp, unordered_map<int, bool> mp,  vector<int> nums)
    {
        if(temp.size()==nums.size())
        {
            res.push_back(temp);
           
        }
        else
        {
            for(int i=0;i<nums.size();i++)
            {
                if(mp[nums[i]]==true)
                    continue;

                mp[nums[i]]=true;
                temp.push_back(nums[i]);
                backtrack(res, temp, mp, nums);
                mp[nums[i]]=false;
                temp.pop_back();
            } 
        }
       
        
        return;
    }
};
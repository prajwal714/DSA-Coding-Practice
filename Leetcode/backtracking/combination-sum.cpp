
// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        backtrack(res, vector<int>(), candidates, 0, target);
        
        return res;
        
    }
    
    void backtrack(vector<vector<int>> &res, vector<int> temp,vector<int> &arr, int sum, int target)
    {
        if(sum>target)
            return;
        
        if(sum==target)
        {
            res.push_back(temp);
            return;
        }
        
        for(int i=0;i<arr.size();i++)
        {
            if(!temp.empty() && arr[i]<temp.back())
                continue;
            
            sum+=arr[i];
            temp.push_back(arr[i]);
            backtrack(res, temp, arr, sum, target);
            temp.pop_back();
            sum-=arr[i];
        }
        return;
    }
};
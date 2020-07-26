class Solution {
public:
   
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n=nums.size();
        int i;
        int size=1<<n;
        vector<vector<int>> res(size);

        
        for(i=0;i<size;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                    res[i].push_back(nums[j]);
            }
        }
        
        return res;
        
    }
};

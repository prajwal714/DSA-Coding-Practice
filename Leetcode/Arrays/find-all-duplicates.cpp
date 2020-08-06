class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
                vector<int> res;

        for(int i=0;i<n;i++)
        {
            int pos=abs(nums[i])-1;
            
            nums[pos]=-1*nums[pos];
            if(nums[pos]>0)
            res.push_back(pos+1);
        }
        
        
        return res;
    }
};
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        
        unordered_map<int,int> mp;
        
        int n=nums.size();
        
        if(n<=0 || k<=0)
            return false;
        
        
        for(int i=0;i<n;i++)
        {
            if(i>k)
            {
                mp[nums[i-k-1]]--;
            }
            
            mp[nums[i]]++;
            
            if(mp[nums[i]]>1)
                return true;
        }
        
        return false;
    }
};
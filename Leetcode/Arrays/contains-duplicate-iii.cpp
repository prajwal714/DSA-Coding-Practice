class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        
        
        int n=nums.size();
        multiset<long> s;
        if(n<=0 || k<=0)
            return false;
        
        int i;
        for(i=0;i<n;i++)
        {
            long num=(long)nums[i];
            if(i>k)
            {
                s.erase(nums[i-k-1]);
            }
            
            auto pos=s.lower_bound(num-t);
            
            if(pos!=s.end() && (long)*pos-num<=t)
                return true;
            
            s.insert(nums[i]);
            
        }
        
        return false;
        
        
    }
};

//complexity: nlogk  logk complexity for set operations, n times for each element in array
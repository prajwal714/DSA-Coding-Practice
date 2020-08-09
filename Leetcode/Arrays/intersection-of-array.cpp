//we have to return all the unique nums which are common in both arrays
//time: O(m+n)
//space: O(min(m,n))
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size()>nums2.size())
            return intersection(nums2,nums1);
        
       unordered_map<int,int> mp;
        vector<int> res;
        for(int n:nums1)
        {
            mp[n]++;
        }
        
        for(int n:nums2)
        {
            if(mp[n]>0)
            {
                res.push_back(n);
                mp[n]=0;
            }
        }
        
        return res;
        
        
        
    }
};
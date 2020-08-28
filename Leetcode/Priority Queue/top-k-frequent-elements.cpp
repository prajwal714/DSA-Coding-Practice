//time complexity: O(n) and space complexity O(n+k)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
      if(nums.size()<1)
          return vector<int>();
        
      unordered_map<int,int> mp;
        for(int n:nums)
            mp[n]++;
        
        priority_queue<pair<int,int>> pq;
        vector<int> res;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            pq.push({it->second, it->first});
            
            if(pq.size()>mp.size()-k)
            {
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        
        return res;
        
    }
};
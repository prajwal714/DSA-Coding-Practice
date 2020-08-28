class Solution {
public:
    struct compare{
        bool operator()(pair<int, string> a, pair<int,string> b)
        {
            if(a.first==b.first)
            {
                return (a.second<b.second);
            }
            else
            return a.first>b.first; 
        }
    };
    
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string, int> mp;
        priority_queue<pair<int,string>, vector<pair<int,string>>, compare> pq;
        for(string s:words)
        {
            mp[s]++;
        }
        
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            pq.push({it->second, it->first});
            
            if(pq.size()>k)
                pq.pop();
        }
        
        vector<string> res;
        
        while(!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
        
        
    }
};
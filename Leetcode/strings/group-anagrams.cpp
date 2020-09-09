class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> mp;
        
        for(int i=0;i<strs.size();i++)
        {
            string s=strs[i];
            sort(s.begin(), s.end());
            
            mp[s].push_back(strs[i]);
            
        }
        
        vector<vector<string>> res;
        
        for(auto v:mp)
        {
            
            res.push_back(v.second);
        }
        
        return res;
    }
};

//time complexity of N*KlogK where k is the max length of any string, N is the size of strs


// we can also use an encoding of number of count of each char eg: aabc===2#1#1#0#0.... of length 26 for each character, then the time complexity will ne N*K


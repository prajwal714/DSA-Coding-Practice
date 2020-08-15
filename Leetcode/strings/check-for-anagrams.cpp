class Solution {
public:
    bool isAnagram(string s, string t) {
        
        unordered_map<char, int> mp;
        
        int i;
        
        
        for(i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }
        
        for(i=0;i<t.length();i++)
        {
            if(mp.find(t[i])!=mp.end())
            {
                 mp[t[i]]--;
                if(mp[t[i]]<0)
                return false;
            }
            else
                return false;
           
            
            
        }
        
        for(auto it=mp.begin(); it!=mp.end();it++)
        {
            if(it->second!=0)
                return false;
        }
        
        return true;
    }
};
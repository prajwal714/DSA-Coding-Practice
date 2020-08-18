class Solution {
public:
    unordered_map<char,int> mp={
        {'I',1},
        {'V',5},
        {'X',10,},
        {'L',50,},
        {'C',100},
        {'D',500},
        {'M',1000}
    
    };
    
    int romanToInt(string s) {
    
        
        if(s.length()==0)
            return 0;
        
        int res=0;
        res+=mp[s.back()];
        
        for(int i=s.length()-2;i>=0;i--)
        {
            if(mp[s[i]]<mp[s[i+1]])
                res-=mp[s[i]];
            else
                res+=mp[s[i]];
        }
        
        return res;
        
        
    }
};
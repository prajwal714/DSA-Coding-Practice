class Solution {
public:
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> res;
        backtrack(res, vector<string>(), 0, s);
        
        return res;
        
    }
    
    void backtrack(vector<vector<string>> &res, vector<string> temp, int start, string s)
    {
        if(start==s.length())
        {
            res.push_back(temp);
            return;
        }
        
        for(int i=start;i<s.length();i++)
        {
           
            if(isPalindrome(s, start, i))
            {
                temp.push_back(s.substr(start, i-start+1));
                backtrack(res, temp, i+1, s);
                temp.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s, int start, int end)
    {
        while(start<end)
        {
            if(s[start++]!=s[end--])
                return false;
        }
        
        return true;
    }
};
class Solution {
public:
    unordered_map<int, vector<char>> mp ={
        {'2', {'a','b','c'}},
        {'3', {'d','e','f'}},
        {'4', {'g','h','i'}},
        {'5', {'j','k','l'}},
        {'6', {'m','n','o'}},
        {'7', {'p','q','r', 's'}},
        {'8', {'t','u','v'}},
        {'9', {'w','x','y', 'z'}},
    };
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.length()==0)
            return res;
        backtrack("", digits, res, 0);
        
        return res;
    }
    
    void backtrack(string op, string digits, vector<string> &res, int pos)
    {
        if(op.length()==digits.length())
        {
            res.push_back(op);
            return;
        }
        
        
        for(char ch: mp[digits[pos]])
        {
            op.push_back(ch);
            backtrack(op, digits, res, pos+1);
            op.pop_back();
        }

        
        
    }
};
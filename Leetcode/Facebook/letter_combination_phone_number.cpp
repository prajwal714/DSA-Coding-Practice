#include <bits/stdc++.h>


/*
create a map of all digits to char combination

Time complexity:
O(n*4^n) since at worst we can have 9999 as digits, and 9 has 4 characters, and we'll have to do the same for n digits

Space complexity:
O(n)


*/
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {

        map<char, string> mp;
        mp = {{'2', "abc"},
              {'3', "def"},
              {'4', "ghi"},
              {'5', "jkl"},
              {'6', "mno"},
              {'7', "pqrs"},
              {'8', "tuv"},
              {'9', "wxyz"}};

        vector<string> res;

        if (digits.length() == 0)
        {
            return res;
        }

        backtrack(mp, res, 0, "", digits);

        return res;
    }

    void backtrack(map<char, string> mp, vector<string> &res, int idx, string ch, string digits)
    {

        if (ch.length() == digits.length())
        {
            cout << ch;
            res.push_back(ch);
            return;
        }

        string str = mp[digits[idx]];
        for (int i = 0; i < str.length(); i++)
        {
            backtrack(mp, res, idx + 1, ch + str[i], digits);
        }
        return;
    }
};
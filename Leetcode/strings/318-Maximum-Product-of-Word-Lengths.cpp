#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<string> &words)
    {

        vector<int> mask(words.size());

        //we create a mask of 26 bits for every word, 1 for char
        for (int i = 0; i < words.size(); i++)
        {
            for (char ch : words[i])
            {
                mask[i] = mask[i] | (1 << (ch - 'a'));
            }
        }
        // we take a & operation between mask[i] and mask[j] of word pair to check if they are mutually exlucisve
        int ans = 0;
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = i + 1; j < words.size(); j++)
            {
                if (!(mask[i] & mask[j]))
                {
                    int prod = words[i].length() * words[j].length();
                    ans = max(ans, prod);
                }
            }
        }

        return ans;
    }
};
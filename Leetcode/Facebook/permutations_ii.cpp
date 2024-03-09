#include <bits/stdc++.h>

/*
We cant choose duplicate elements to be the first elements in ds result array, otherwise w'll get 
duplicate results, thats why we use a map and use the duplicate value only once

Time complexity: Worst case all digits are different O(N*N!)

Space complexity: 3*O(N) ~ O(N)
*/

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {

        map<int, int> frq;
        vector<int> ds;

        vector<vector<int>> res;

        for (int i = 0; i < nums.size(); i++)
        {
            frq[nums[i]]++;
        }

        permuteRecur(res, ds, frq, nums);
        return res;
    }

    void permuteRecur(vector<vector<int>> &ans, vector<int> &ds, map<int, int> frq, vector<int> &nums)
    {

        if (ds.size() == nums.size())
        {
            ans.push_back(ds);
            return;
        }

        for (auto it : frq)
        {
            if (it.second == 0)
                continue;

            frq[it.first]--;
            ds.push_back(it.first);

            permuteRecur(ans, ds, frq, nums);
            ds.pop_back();
            frq[it.first]++;
        }
    }
};
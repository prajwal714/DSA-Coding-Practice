#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<TreeNode *> s;
    vector<int> t1;
    while (root1 != NULL || !s.empty())
    {
        while (root1 != NULL)
        {
            s.push(root1);

            root1 = root1->left;
        }

        root1 = s.top();
        s.pop();

        t1.push_back(root1->val);

        root1 = root1->right;
    }
}

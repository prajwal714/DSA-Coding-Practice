/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int depth(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        return 1 + max(depth(root->left), depth(root->right));
    }

    void traverse(TreeNode *root, int level, vector<vector<int> > &res)
    {
        if (root == NULL)
            return;

        res[level].push_back(root->val);

        traverse(root->left, level - 1, res);
        traverse(root->right, level - 1, res);
    }

    vector<vector<int> > levelOrderBottom(TreeNode *root)
    {
        int d = depth(root);

        vector<vector<int> > res(d);

        traverse(root, d - 1, res);

        return res;
    }
};
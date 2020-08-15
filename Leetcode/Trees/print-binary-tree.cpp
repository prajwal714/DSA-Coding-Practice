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
class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        
        int ht=height(root);
        
        int col=(1<<ht)-1;
        int row=ht;
        
        vector<vector<string>> res(row, vector<string> (col, ""));
        
        helper(root, 0, 0, col-1, res);
        
        return res;
        
        
    }
    
    void helper(TreeNode* root,int level,  int l, int r, vector<vector<string>> &res)
    {
        if(root==NULL)
            return;
        
        res[level][(l+r)/2]=to_string(root->val);
        
        helper(root->left, level+1, l, (l+r)/2, res);
        helper(root->right, level+1, (l+r)/2+1, r, res);
        
    }
    
    int height(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        
        int left=height(root->left);
        int right=height(root->right);
        
        return 1+max(left, right);
    }
};
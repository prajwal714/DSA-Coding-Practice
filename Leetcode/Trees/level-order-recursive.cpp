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
    
    int height(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        
        int left=height(root->left);
        int right=height(root->right);
        
        return 1+max(left,right);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        if(root==NULL)
            return {};
        
        int ht=height(root);
        
        
        vector<vector<int>> res(ht);
        
        levelorder(res, root, ht-1);
        
        return res;
        
        
        
        
    }
    
    void levelorder(vector<vector<int>> &res, TreeNode* root, int level)
    {
        if(root==NULL)
            return;
        
        res[level].push_back(root->val);
        
        levelorder(res,root->left, level-1);
        levelorder(res, root->right, level-1);
        
        return;
    }
};
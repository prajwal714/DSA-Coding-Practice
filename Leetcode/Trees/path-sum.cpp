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
    bool hasPathSum(TreeNode* root, int sum) {
        
        return helper(root, 0, sum);
        
    }
    
    bool helper(TreeNode* root, int sum, int target)
    {
        if(root==NULL)
            return false;
        
        if(root->left==NULL && root->right==NULL)
        {
            sum+=root->val;
            if(sum==target)
                return true;
        }
        
        bool left=helper(root->left, sum+root->val, target);
       bool right=helper(root->right, sum+root->val, target);
        
        return left || right;
    }
};
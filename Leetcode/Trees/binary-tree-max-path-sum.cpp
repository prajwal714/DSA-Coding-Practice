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
    int res;
    int maxPathSum(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        res=INT_MIN;
        maxSum(root);
        return res;
        
    }
    
    int maxSum(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        
        int left=maxSum(root->left);
        if(left<0)
            left=0;
        int right=maxSum(root->right);
        if(right<0)
            right=0;
        
        int ans=max(max(left,right)+root->val, root->val);
        
        res=max(res, left+right+root->val);
        
        return ans;
    }
};
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
    int sumNumbers(TreeNode* root) {
        
        res=0;
        helper(root, 0);
        
        return res;
    }
    
    int helper(TreeNode* root, int sum)
    {
        if(root==NULL)
            return 0;
        
        int num=sum*10+root->val;
        
        if(root->left==NULL && root->right==NULL)
            res+=num;
        
        return helper(root->left,num)+helper(root->right, num);
    }
};
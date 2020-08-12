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
    bool isLeaf(TreeNode* root)
    {
        if(root==NULL)
            return false;
        
        if(root->left==NULL && root->right==NULL)
            return true;
        else
            return false;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        
        if(root==NULL)
        return 0;
        
        int sum=0;
        
        if(isLeaf(root->left))
           sum= root->left->val;
       
        
        
        return sum+sumOfLeftLeaves(root->left)+ sumOfLeftLeaves(root->right);
        
    }
};
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
    int res;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
       res=1;
        depth(root);
        
        return res-1;
        
    }
    
    int depth(TreeNode* root)
    {
        if(root==NULL)
            return 0;
         
        int left=depth(root->left);
        int right=depth(root->right);
        
        res=max(res, left+right+1);
        
        return max(left,right)+1;
        
    }
};
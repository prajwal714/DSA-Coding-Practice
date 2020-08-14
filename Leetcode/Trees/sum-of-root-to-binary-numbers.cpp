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
    int sumRootToLeaf(TreeNode* root) {
       res=0;
        return inorder(root, 0);
        
      
        
    }
    
    int inorder(TreeNode* root, int val)
    {
        if(root==NULL)
            return 0;
        
        val=val*2+root->val;
        
        if(root->left==NULL && root->right==NULL)
            return val;
        else
            return inorder(root->left, val)+inorder(root->right, val);
    }
};
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if(root==NULL)
            return new TreeNode(val);
        
        if(root->left==NULL && val<root->val)
        {
            TreeNode* temp=new TreeNode(val);
            root->left=temp;
            return root;
            
        } 
        else if(root->right==NULL && val>root->val)
        {
            TreeNode* temp=new TreeNode(val);
            root->right=temp;
            return root;
        }
        
        if(val<root->val)
            insertIntoBST(root->left, val);
        else
            insertIntoBST(root->right, val);
        
        return root;
        
    }
};
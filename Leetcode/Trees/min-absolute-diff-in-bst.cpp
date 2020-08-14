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
    int getMinimumDifference(TreeNode* root) {
        
        int res=INT_MAX;
        TreeNode* pre=NULL;
        inorder(root, pre, res);
        
        return res;
        
    }
    
    void inorder(TreeNode* root, TreeNode* &pre, int &res)
    {
        if(root==NULL)
            return;
        
        inorder(root->left, pre, res);
        
        if(pre!=NULL)
            res=min(res, abs(pre->val-root->val));
        
        pre=root;
       
        inorder(root->right, pre, res);
    }
};
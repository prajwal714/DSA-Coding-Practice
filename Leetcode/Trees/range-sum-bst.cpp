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
    int rangeSumBST(TreeNode* root, int L, int R) {
        res=0;
        
        dfs(root,L,R);
        return res;
        
    }
    
    void dfs(TreeNode* root, int l, int r)
    {
        if(root==NULL)
            return;
        
        if(l<=root->val && root->val<=r)
            res+=root->val;
        
        if(l<root->val)
            dfs(root->left,l,r);
        
        if(root->val<r)
            dfs(root->right,l,r);
        
        return;
    }
};
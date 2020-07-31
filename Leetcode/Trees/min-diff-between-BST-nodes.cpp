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
private: 
    int res=INT_MAX,pre=-1;
public:
    int minDiffInBST(TreeNode* root) {
        
       
        
        if(root->left)
            minDiffInBST(root->left);
        
        if(pre>0)
           res=min(res, abs(pre-root->val));
        
        pre=root->val;
        
        if(root->right)
            minDiffInBST(root->right);
        
        return res;
        
        
    }
};
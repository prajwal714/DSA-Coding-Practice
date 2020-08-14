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
    bool isBalanced(TreeNode* root) {
        
        if(root==NULL)
            return true;
        
        bool res=true;
        height(root, res);
        return res;
    }
    
    int height(TreeNode* root, bool &res)
    {
        if(root==NULL)
            return 0;
        
        int left=height(root->left, res);
        int right=height(root->right, res);
        
        int ht=max(left,right)+1;
        int diff=abs(left-right);
            if(diff>1)
                res=false;
        
        return  ht;
    }
};
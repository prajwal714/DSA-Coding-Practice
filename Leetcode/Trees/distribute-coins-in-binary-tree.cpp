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
    int ans;
    int distributeCoins(TreeNode* root) {
        ans=0;
        dfs(root);
        return ans;
    }
    
    int dfs(TreeNode* node)
    {
        if(node==NULL)
            return 0;
        
        int l=dfs(node->left);
        int r=dfs(node->right);
        
        ans+=abs(l)+abs(r);
        return node->val+l+r-1;
    }
};
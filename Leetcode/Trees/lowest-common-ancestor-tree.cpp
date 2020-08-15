/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* res;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root==NULL)
            return root;
        res=NULL;
        recurse(root,p,q);
        
        return res;
        
        
    }
    
    bool recurse(TreeNode* root, TreeNode* p, TreeNode* q)
    {
     
        if(root==NULL)
            return false;
        
        bool left=recurse(root->left, p,q);
        bool right=recurse(root->right,p,q);
        
        
       bool mid=(p->val==root->val || q->val==root->val)?true:false;
           
        
        if(mid&&left || mid&&right || left&&right)
        {
            res=root;
        }
        
        return mid||left||right;
        
    }
};
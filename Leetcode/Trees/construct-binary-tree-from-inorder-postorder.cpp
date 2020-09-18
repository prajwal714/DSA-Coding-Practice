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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        return buildTree(inorder, postorder, inorder.size()-1, 0, inorder.size()-1);
        
    }
    
    TreeNode* buildTree(vector<int>&inorder, vector<int> &postorder, int pos, int in_start, int in_end)
    {
        if(in_start>in_end)
            return NULL;
        
        if(in_start==in_end)
            return new TreeNode(postorder[pos]);
        
        TreeNode* root=new TreeNode(postorder[pos]);
        
        int in_pos;
        for(int i=in_start;i<=in_end;i++)
        {
            if(inorder[i]==root->val)
            {
                in_pos=i;
                break;
            }
                
        }
        root->right=buildTree(inorder, postorder, pos-1, in_pos+1, in_end);
        
        int right_nodes=in_end-in_pos+1;
        
        root->left=buildTree(inorder, postorder, pos-right_nodes, in_start, in_pos-1);
        
        return root;
    }
};
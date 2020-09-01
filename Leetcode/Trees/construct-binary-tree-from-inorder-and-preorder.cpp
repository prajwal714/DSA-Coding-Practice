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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        return helper(0, 0, inorder.size()-1, preorder, inorder);
    }
    
    TreeNode* helper(int pos, int inStart, int inEnd, vector<int> &preorder, vector<int> &inorder)
    {
        if(pos<inStart || inStart>inEnd)
            return NULL;
        
        TreeNode* root=new TreeNode(preorder[pos]);
        int inPos;
        for(int i=inStart;i<=inEnd;i++)
        {
            if(inorder[i]==root->val)
            {
                inPos=i;
                break;
            }
                
        }
        
        root->left=helper(pos+1, inStart, inPos-1, preorder, inorder );
        root->right=helper(pos+inPos-inStart+1, inPos+1, inEnd, preorder, inorder);
        
        return root;
    }
};
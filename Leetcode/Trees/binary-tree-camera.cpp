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
    int minCameraCover(TreeNode* root) {
        res=0;
        
        if( dfs(root)<1)
            res+=1;
        
        return res;
        
    }
    
    int dfs(TreeNode* root)
    {
        if(root==NULL)
            return 2;
        
        int left=dfs(root->left);
        int right=dfs(root->right);
        
        if(left==0||right==0)
        {
            res++;
            return 1;  //parent of leaf node
        }
        
        if(right==1||left==1)
        {
            return 2;  //grad parent of leaf node
        }
        else
            return 0; //leaf ode
    }
};
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
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        
        vector<vector<int>> res;
        int sum=0;
        vector<int> v;
        helper(root, 0, target, res,v);
        return res;
        
        
    }
    
    void helper(TreeNode* root, int sum,int target, vector<vector<int>> &res, vector<int> v)
    {
        if(root==NULL)
            return;
        
        
        v.push_back(root->val);
        sum+=root->val;
        
        if(root->left==NULL && root->right==NULL)
        {
            if(sum==target)
                res.push_back(v);
            return;
        }
        else
        {
            helper(root->left, sum, target, res,v);
            helper(root->right, sum,target, res,v);
        }
        
        
    }
};
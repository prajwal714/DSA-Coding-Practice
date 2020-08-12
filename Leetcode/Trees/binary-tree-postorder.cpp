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
    vector<int> postorderTraversal(TreeNode* root) {
        
        stack<TreeNode*> s;
        
        if(root==NULL)
            return vector<int> {};
        
        
        s.push(root);
        vector<int> res;
        while(!s.empty())
        {
            TreeNode* temp=s.top();
            s.pop();
            
            if(temp->left)
                s.push(temp->left);
            
            if(temp->right)
                s.push(temp->right);
            
            res.push_back(temp->val);
            
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};
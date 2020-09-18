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
        
        if(root==NULL)
            return {};
        
        stack<TreeNode*> s;
        s.push(root);
        vector<int> res;
        while(!s.empty())
        {
            TreeNode* temp=s.top();
            s.pop();
            
            res.push_back(temp->val);
            
            if(temp->left)
                s.push(temp->left);
            
            if(temp->right)
                s.push(temp->right);
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};

//this is similar to preoder, but we just traverse the right root first, then left root, then root

//and reverse the result at the end
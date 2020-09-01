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
    int findSecondMinimumValue(TreeNode* root) {
        
        TreeNode* prev=NULL;
        stack<TreeNode*> s;
        
        long int min1=LONG_MAX, min2=LONG_MAX;
        
        while(root!=NULL || !s.empty())
        {
            while(root)
            {
                s.push(root);
                root=root->left;
            }
            
            root=s.top();
            s.pop();
            
           if(root->val<min1)
           {
               min2=min1;
               min1=root->val;
           }
            else if(root->val<min2 && root->val!=min1)
            {
                min2=root->val;
            }
            
            root=root->right;
        }
        
        if(min2==LONG_MAX)
            return -1;
        else
            return min2;
    }
};
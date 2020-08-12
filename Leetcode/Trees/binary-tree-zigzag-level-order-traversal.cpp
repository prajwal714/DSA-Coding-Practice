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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        queue<TreeNode*> q;
        int k=0;
        if(root==NULL)
            return res;
        
        q.push(root);
        
        while(!q.empty())
        {
            int size=q.size();
            vector<int> level;
            
            while(size--)
            {
                TreeNode* temp=q.front();
                q.pop();
                
                if(temp->left)
                    q.push(temp->left);
                
                if(temp->right)
                    q.push(temp->right);
                
                level.push_back(temp->val);
                
            }
            k++;
            
            //we can also sun a for loop and push from the back or from the front instead of reversing the vector


            if(k%2==0)
                reverse(level.begin(), level.end());
            
            res.push_back(level);
            
            
        }
        
        return res;
    }
};
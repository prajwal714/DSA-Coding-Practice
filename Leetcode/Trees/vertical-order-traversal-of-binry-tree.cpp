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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, set<int>> > mp;
        vector<vector<int>> res;
        inorder(root, mp, 0,0);
        
        for(auto it=mp.begin(); it!=mp.end();it++ )
        {
           res.push_back(vector<int> ());
            for(auto i=it->second.begin(); i!=it->second.end();i++)
            {
                res.back().insert(end(res.back()), begin(i->second), end(i->second));
            }
           
        }
        
        return res;
        
    }
    
    void inorder(TreeNode* root, map<int, map<int, set<int>> > &mp, int k, int level)
    {
        if(root==NULL)
            return;
        
        mp[k][level].insert(root->val);
        inorder(root->left, mp, k-1, level+1);
    
        
        inorder(root->right, mp, k+1, level+1);
    }
};
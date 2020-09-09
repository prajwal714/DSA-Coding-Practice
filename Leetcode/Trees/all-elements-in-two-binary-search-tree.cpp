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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        vector<int> t1,t2;
        
        stack<TreeNode*> s;
        
       
        
        while(root1!=NULL || !s.empty())
        {
            while(root1!=NULL)
            {
                s.push(root1);
                
                root1=root1->left;
                
            }
            
            root1=s.top();
            s.pop();
            
            t1.push_back(root1->val);
            
            root1=root1->right;
        }
        
        
        
        while(root2!=NULL || !s.empty())
        {
            while(root2!=NULL)
            {
               
                    s.push(root2);
                
                root2=root2->left;
                
            }
            
            root2=s.top();
            s.pop();
            
            t2.push_back(root2->val);
            
            root2=root2->right;
        }
        
        int i=0,j=0;
        vector<int> res;
        while(i<t1.size() && j<t2.size())
        {
            if(t1[i]<t2[j])
            {
                res.push_back(t1[i]);
                i++;
            }
            else
                res.push_back(t2[j++]);
        }
        
        while(i<t1.size())
            res.push_back(t1[i++]);
        
        while(j<t2.size())
            res.push_back(t2[j++]);
        
        return res;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* res;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root==NULL)
            return root;
        res=NULL;
        recurse(root,p,q);
        
        return res;
        
        
    }
    
    bool recurse(TreeNode* root, TreeNode* p, TreeNode* q)
    {
     
        if(root==NULL)
            return false;
        
        bool left=recurse(root->left, p,q); // we check if either p or q is present in left subtree
        bool right=recurse(root->right,p,q); // we check if p or q is present in right subtree
        
        
       bool mid=(p->val==root->val || q->val==root->val);  // we check if current root is either p or q
           
        
        if(left&&right || left&&mid && right&&mid) //if any two of the condition is true, we have found a common ancestor and update the result  
        {
            res=root;
        }
        
        return mid||left||right;  //return true, if either of the 3 condition is true
        
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//Iterative solution using a hash map to store parent of each Node, and find the first common ancestor of 
//both p and q



class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        unordered_map<TreeNode*, TreeNode*> parent;
        
        stack<TreeNode*> s;
       parent[root]=NULL;
        s.push(root);
        while(parent.find(p)==parent.end() || parent.find(q)==parent.end())
        {
            TreeNode* temp=s.top();
            s.pop();
            
            if(temp->left)
            {
                parent[temp->left]=temp;
                s.push(temp->left);
            }
            
            if(temp->right)
            {
                parent[temp->right]=temp;
                s.push(temp->right);
            }
        }
        
        set<TreeNode*> ancestor;
        
        while(p!=NULL)
        {
            ancestor.insert(p);
            p=parent[p];
        }
        
        while(ancestor.find(q)==ancestor.end())
        {
            q=parent[q];
        }
        
        return q;
    }
};
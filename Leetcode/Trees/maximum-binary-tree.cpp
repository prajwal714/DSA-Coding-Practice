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

//O(N^2) time complexity
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        
        return helper(nums, 0, nums.size()-1);
        
        
    }
    
    
   TreeNode* helper(vector<int> &nums, int left, int right  )
    {
      if(left>right)return NULL;
        
        int max_index = left;
        for(int i = left; i<=right; i++){
            if(nums[i] > nums[max_index])max_index = i; 
        }
        
        TreeNode* root = new TreeNode(nums[max_index]);
        root->left = helper(nums, left, max_index - 1);
        root->right = helper(nums, max_index + 1, right);
        return root;
    }
    
   
};

//======================================O(N) solution using stack

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        
       stack<TreeNode*> s;
        for(int num:nums)
        {
            TreeNode* curr=new TreeNode(num);
            
            while(!s.empty()&& s.top()->val<curr->val)
            {
                curr->left=s.top();
                s.pop();
            }
            
            if(!s.empty())
                s.top()->right=curr;
            
            s.push(curr);
        }
        
        while(s.size()>1)
            s.pop();
        
        return s.top();
        
        
    }
    
    
 
   
};
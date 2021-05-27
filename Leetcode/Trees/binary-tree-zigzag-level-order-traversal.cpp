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

//this is the wrong implementation, we cannot reverse the vector its not a true zig zag traversal
// class Solution {
// public:
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

//         vector<vector<int>> res;
//         queue<TreeNode*> q;
//         int k=0;
//         if(root==NULL)
//             return res;

//         q.push(root);

//         while(!q.empty())
//         {
//             int size=q.size();
//             vector<int> level;

//             while(size--)
//             {
//                 TreeNode* temp=q.front();
//                 q.pop();

//                 if(temp->left)
//                     q.push(temp->left);

//                 if(temp->right)
//                     q.push(temp->right);

//                 level.push_back(temp->val);

//             }
//             k++;

//             //we can also sun a for loop and push from the back or from the front instead of reversing the vector

//             if(k%2==0)
//                 reverse(level.begin(), level.end());

//             res.push_back(level);

//         }

//         return res;
//     }
// };

class Solution
{
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root)
    {
        if (root == NULL)
            return {};

        deque<TreeNode *> q;

        q.push_back(root);
        bool l2r = true;
        vector<vector<int> > res;

        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;
            while (size--)
            {
                TreeNode *temp;
                if (l2r)
                //when left->right pop_back and push_front (left child, right child)
                {
                    temp = q.back();
                    q.pop_back();

                    if (temp->left)
                        q.push_front(temp->left);
                    if (temp->right)
                        q.push_front(temp->right);
                }
                else
                //when right->left pop_front and push_back(right child, left child)
                {
                    temp = q.front();
                    q.pop_front();

                    if (temp->right)
                        q.push_back(temp->right);
                    if (temp->left)
                        q.push_back(temp->left);
                }
                level.push_back(temp->val);
            }
            l2r = !l2r;
            res.push_back(level);
        }

        return res;
    }
};
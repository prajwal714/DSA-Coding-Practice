#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//in this we have to return the boundary elements of a tree in anticlockwise fashion
class Solution {
    bool isLeaf(TreeNode* root) {
        return !root->left && !root->right;
    }

    //this function adds leaves to the vector res, in left to right fashion
    void addLeaves(TreeNode* root, vector<int>& res) {

        //we traverse the nodes in preorder fashio to add leaves
        if (isLeaf(root)) {
            res.push_back(root->val);
            return;
        }
        if (root->left) addLeaves(root->left, res);
        if (root->right) addLeaves(root->right, res);
    }
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (!root) return {};

        vector<int> res;
        if (!isLeaf(root)) res.push_back(root->val);
        // add left boundary
        TreeNode* cur = root->left;
        while (cur) {
            if (!isLeaf(cur)) res.push_back(cur->val);
            if (cur->left) cur = cur->left;
            else cur = cur->right;
        }
        // add leaf nodes
        addLeaves(root, res);

        cur = root->right;
        stack<int> tmp;        // add right boundary
        while (cur) {
            if (!isLeaf(cur)) tmp.push(cur->val);
            if (cur->right) cur = cur->right;
            else cur = cur->left;
        }
        while(!tmp.empty())
            res.push_back(tmp.top());
            tmp.pop();
        }
        return res;
    }
};
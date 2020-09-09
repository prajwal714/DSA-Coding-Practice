/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        
        return depth(root);
    }
    
    
    int depth(Node* root)
    {
        if(root==NULL)
            return 0;
        
        int max_depth=0;
        
        for(auto child:root->children)
        {
            int child_depth=depth(child);
            
            max_depth=max(max_depth, child_depth);
        }
        
        return 1+max_depth;
    }
};
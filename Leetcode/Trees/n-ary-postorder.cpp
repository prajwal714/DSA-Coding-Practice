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
    vector<int> res;
    vector<int> postorder(Node* root) {
        if(root==NULL)
            return vector<int>{};
        postorderHelper(root);
      
        return res;
        
            
    }
    
    void postorderHelper(Node* root)
    {
        if(root==NULL)
            return;
        
        for(auto child: root->children)
        {
            postorderHelper(child);
        }
        res.push_back(root->val);

        
        return;
    }
};


//iterative

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
    vector<int> res;
    vector<int> postorder(Node* root) {
       
        if(root==NULL)
            return vector<int> {};
        
        stack<Node*> s;
        s.push(root);
        
        while(!s.empty())
        {
            Node* temp=s.top();
            s.pop();
            
            for(auto child: temp->children)
            {
                s.push(child);
            }
            
            res.push_back(temp->val);
        }
        
        reverse(res.begin(), res.end());
        
        return res;
        
        
    }
};

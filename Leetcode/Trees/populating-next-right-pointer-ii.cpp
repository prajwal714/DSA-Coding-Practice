/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

//this is similar to level order traversal but: it uses constant space instead of queue space. 

class Solution {
public:
    Node* connect(Node* root) {
        
        if(root==NULL)
            return root;
        
        Node* parent=root; //here we use 3 pointers, prent points to the current level parent
        Node* childHead=NULL, *child=NULL; //childHead points to the first node of next level, child points to the children of each parent in current node iteratively
        
        while(parent!=NULL) //traverses each level by level untill parent becomes null by reaching the last level
        {
            while(parent!=NULL)  //traverses a level, parent=parent->next until null
            {
                if(parent->left!=NULL)
                {
                    if(childHead==NULL)
                    {
                        childHead=parent->left;
                    }
                    else
                        child->next=parent->left;
                    
                    child=parent->left;
                }
                
                if(parent->right!=NULL)
                {
                    if(childHead==NULL)
                    {
                        childHead=parent->right;
                    }
                    else
                        child->next=parent->right;
                    
                    child=parent->right;
                }
                
                parent=parent->next;
            }
            
            parent=childHead;
            child=NULL; childHead=NULL;
        }
        
        return root;
        
    }
};
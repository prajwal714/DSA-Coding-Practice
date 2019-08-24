//Print path from root to every Leaf


#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
void printPaths(struct Node *root);
struct Node* newNode(int data)
{
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
void inorder(struct Node* root)
{
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->data<<' ';
    inorder(root->right);
}
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  cin>>t;
  while (t--)
  {
     map<int, Node*> m;
     int n;
     cin>>n;
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        cin>>n1>>n2>>lr;
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     printPaths(root);
  }
  return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/* Structure of Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};*/
/* The function should print all the paths from root
 to leaf nodes of the binary tree */
void printUtil(Node* root, string str)
{
    if(root==NULL)
    return;
    
    if(root->right==NULL&&root->left==NULL)
    {
        
        cout<<str<<root->data<<" #";
        
    }
    printUtil(root->left,str+to_string(root->data)+" ");
    printUtil(root->right,str+to_string(root->data)+" ");
}
 
void printPaths(Node* root)
{
    printUtil(root,"");
    cout<<endl;
}

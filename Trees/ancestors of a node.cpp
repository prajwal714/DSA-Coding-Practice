//print ancestors of a given node

{
#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct Node
{
int data;
struct Node* left;
struct Node* right;
};
bool printAncestors(struct Node *root, int target);
struct Node* newNode(int data)
{
struct Node* node = (struct Node*)malloc(sizeof(struct Node));
node->data = data;
node->left = NULL;
node->right = NULL;
return(node);
}
int main()
{
  int t;
  struct Node *child;
  scanf("%d
", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d
",&n);
     struct Node *root = NULL;
     if(n==1)
     {
        int a;
        cin>>a;
        cout<<a<<endl;
     }else{
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
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
     int a;
     cin>>a;
    printAncestors(root, a);
  }
  }
  return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
/*
Structure of a node is as following
struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};
*/
// Function should print all the ancestor of the target node
bool recur(Node* root,int target)
{
    if(root==NULL)
    return false;
    
    if(root->data==target)
    return true;
    
    if(recur(root->left,target)||recur(root->right,target))
    {
        cout<<root->data<<" ";
        return true;
    }
    
    return false;
}
bool printAncestors(struct Node *root, int target)
{
     recur(root,target);
     cout<<endl;
     return true;
     
}


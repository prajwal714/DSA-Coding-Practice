//Print All Nodes at kth Level in Binary Tree

#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
void printKdistance(struct Node *root, int k);
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
  struct Node* node = (struct Node*)
                       malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n,k;
     scanf("%d%d",&n,&k);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
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
     printKdistance(root,k);
     cout << endl;
  }
  return 0;
}


/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
// function should print the nodes at k distance from root
void printKdistance(Node *root, int k)
{
  queue <Node*> q;
  q.push(root);
  int level=0;
  while(!q.empty())
  {
      int size=q.size();
      
      while(size--)
      {
          if(level==k)
          {
              while(!q.empty())
              {
                  Node* temp=q.front();
                  cout<<temp->data<<" ";
                  q.pop();
              }
              return;
          }
          
          Node* curr=q.front();
          
          if(curr->left)
          q.push(curr->left);
          
          if(curr->right)
          q.push(curr->right);
          
         
          
          q.pop();
      }
      level++;
  }
  return;
}

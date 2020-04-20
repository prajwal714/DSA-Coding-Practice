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
void printdistance(Node *root, int startN,int endN)
{
  queue <Node*> q;
  q.push(root);
  int level=0;
  int distance=0;
//  bool begin=false;
//  bool end=false;
  while(!q.empty())
  {
      int size=q.size();
      int arr[pow(2,level)]={-1};
      int currPos=0;
      int startPos=0;
      while(size--)
      {
//         
          
          Node* curr=q.front();
          
           
          if(curr->data==startN)
          startPos=currPos;
          
          
          if(curr->left)
          q.push(curr->left);
          else
          {
          	curr->left=newNode(-1);
          	q.push(curr->left);
		  }
		
		
		
          if(curr->right)
          q.push(curr->right);
          else
          {
          	curr->right=newNode(-1);
          	q.push(curr->right);
		  }
         
          
          q.pop();
      }
      if(begin&&end)
      {
      	cout<<"Node Found at "<<level<<endl;
      	break;
	  }
      level++;
  }
  cout<<"Distance between nodes: "<<distance<<endl;
  
  return;
}

int main()
{
  
     map<int, Node*> m;
     int n;
       struct Node *child;

    cout<<"Enter size of tree: "<<endl;
    cin>>n;
    
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
     int startN,endN;
     cout<<"enter start and end node: "<<endl;
     cin>>startN>>endN;
     printdistance(root,startN,endN);
     cout << endl;
 
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



#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
void topView(struct Node *root);
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  cin >> t;
  while (t--)
  {
     map<int, Node*> m;
     int n;
     cin >> n;
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     topView(root);
     cout << endl;
  }
  return 0;
}


/*This is a function problem.You only need to complete the function given below*/
//Structure of binary tree
/*struct Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
// function should print the topView of the binary tree
void mapNode(Node* root,map<int,vector<int>> &m)
{
    queue<pair<Node*,int>> q;
    q.push(make_pair(root,0));
    
    while(q.size()!=0)
    {
        pair<Node*,int> curr=q.front();
        m[curr.second].push_back(curr.first->data);
        q.pop();
        
        if(curr.first->left)
        {
            q.push(make_pair(curr.first->left,curr.second-1));
        }
        if(curr.first->right)
        {
            q.push(make_pair(curr.first->right,curr.second+1));
        }
    }
    
    
}
void topView(struct Node *root)
{
    map<int,vector<int>> m;
    
    mapNode(root,m);
    
    for(auto it=m.begin();it!=m.end();it++)
    {
        cout<<it->second[0]<<" ";
    }
    
}

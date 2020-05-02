#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* left;
    Node* right;
    int data;
    
  
};

Node* newNode(int data)
{
    Node* temp=new Node;
    temp->left=NULL;
    temp->right=NULL;
    temp->data=data;
    
    return temp;
}

Node* buildTree( int arr[], int low, int high)
{
    if(low>high)
    return NULL;
    
   
  
    int mid=(low+high)/2;
    Node* root=newNode(arr[mid]);
    
 
   
    root->left=buildTree( arr, low, mid-1);
    root->right=buildTree( arr, mid+1, high);
   return root;
    
    
}

void preorder(Node* root)
{
    if(root==NULL)
    return;
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n;
         cin>>n;
         int arr[n];
         
         int i;
         for(i=0;i<n;i++)
         cin>>arr[i];
         
         Node* root=buildTree(arr,0,n-1);
         preorder(root);
         cout<<endl;
     }
     return 0;
 }
         
         
         
         
         
         
         
  

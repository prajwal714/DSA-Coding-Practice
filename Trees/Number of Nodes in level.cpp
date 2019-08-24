
#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *left,*right;
};
Node *newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
 
    return (temp);
}
void insert(Node *root,int a1,int a2,char lr){
	if(root==NULL){
		return;
	}
	if(root->data==a1){
		switch(lr){
			case 'L':root->left=newNode(a2);
			break;
			case 'R':root->right=newNode(a2);
			break;
		}
	}
	else{
		insert(root->left,a1,a2,lr);
		insert(root->right,a1,a2,lr);
	}
}
void inorder(Node *root){
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
int maxNodeLevel(Node *root1);
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	while(t-->0)
	{
		int n;
		cin>>n;
		int m=n;
		Node *root1=NULL;
		while(n-->0){
			int a1,a2;
			cin>>a1>>a2;
			char lr;
			scanf(" %c",&lr);
			if(root1==NULL){
				root1=newNode(a1);
				switch(lr){
					case 'L':root1->left=newNode(a2);
					break;
					case 'R':root1->right=newNode(a2);
					break;
				}
			}
			else{
				insert(root1,a1,a2,lr);
			}
		}
			cout"Level with max Nodes: "<<maxNodeLevel(root1)<<";"<<endl;
	}
}

/*This is a function problem.You only need to complete the function given below*/
/*Complete the function below
Node is as follows:
struct Node{
	int data;
	Node *left,*right;
};
*/
int maxNodeLevel(Node *root)
{
   queue <Node*> q;
   q.push(root);
   int maxNodes=-1,maxLevel=-1;
   int level=0;
   Node* curr;
   while(!q.empty())
   {
       
       
       int size=q.size();
       
       if(size>maxNodes)
       {
           maxNodes=size;
           maxLevel=level;
       }
       cout<<"Max Nodes: "<<maxNodes<<" Max Level: "<<maxLevel<<endl;
       
       while(size)
       {
           curr=q.front();
           if(curr->left)
           q.push(curr->left);
           
           if(curr->right)
           q.push(curr->right);
           
           q.pop();
           size--;
       }
       level++;
       
       
       
   }
   return maxLevel;
}

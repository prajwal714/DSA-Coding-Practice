#include<bits/stdc++.h>
using namespace std;

class node{
	
	public:
		int data;
		node* left,*right;
};

node* newNode(int data)
{
	node *temp=new node();
	temp->data=data;
	
	temp->right=NULL;
	temp->left=NULL;
	return temp;
}

void diagonalSumUtil(node* root,int vd,map<int,int> &ds)
{
	if(root==NULL)
	return;
	
	ds[vd]+=root->data;
	
	diagonalSumUtil(root->left,vd+1,ds);
	diagonalSumUtil(root->right,vd,ds);
	
	return;
}

void diagonalSum(node* root)
{
	map<int,int> ds;
	map<int,int> ::iterator it;
	
	diagonalSumUtil(root,0,ds);
	cout<<"Sum of diagonals: "<<endl;
	for(it=ds.begin();it!=ds.end();it++)
	{
		cout<<"Sum of level: "<<it->first<<" equals : "<<it->second<<endl;
	}
	
}

int main()
{
	
	//create a neq tree
	node *root=newNode(0);
	root->left=newNode(1);
	root->right=newNode(2);
	root->left->left=newNode(3);
	root->left->right=newNode(4);
	root->right->left=newNode(5);
	root->right->right=newNode(6);
	
	diagonalSum(root);
	
}

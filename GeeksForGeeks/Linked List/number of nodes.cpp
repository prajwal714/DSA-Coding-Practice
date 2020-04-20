//count the number of nodes in a LL recursive and iterati ve
#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* next;
};

void newNode(node** head,int data)
{
	node* temp=new node();
	temp->data=data;
	temp->next=NULL;
	
	if(*head==NULL)
	{
		*head=temp;
	}
	else
	{
		node* pointer=*head;
		while(pointer->next!=NULL)
		{
			pointer=pointer->next;
		}
		pointer->next=temp;
	}
	
	
}
int main()
{
	node *head=NULL;
	newNode(&head,10);
	newNode(&head,20);
	newNode(&head,30);
	
	node* pointer=head;
	while(pointer !=NULL)
	{
		cout<<pointer->data<<"->";
		pointer=pointer->next;
	}
	return 0;
}



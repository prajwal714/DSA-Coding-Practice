//point to the nth node from the end in a link list

#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* next;
};

void findNthNode(node** head,int n)
{
	node* first=*head;
	node* second=*head;
	int i=1;
	while(i<=n)
	{
		second=second->next;
		i++;
	}
	while(second!=NULL)
	{
		first=first->next;
		second=second->next;
	}
	
	cout<<"The nth element is: "<<first->data<<endl;
	
	
}

void newNode(node** head,int data)
{
	node* temp= new node();
	temp->data=data;
	temp->next=*head;
	*head=temp;
	
	
}

int main()
{
	node* head = NULL;
	newNode(&head,20);
	newNode(&head,30);
	newNode(&head,40);
	newNode(&head,50);
	node* pointer=head;
	
	findNthNode(&head,4);
	while(pointer!=NULL)
	{
		cout<<pointer->data<<"->";
		pointer=pointer->next;
		
	}
	return 0;
}

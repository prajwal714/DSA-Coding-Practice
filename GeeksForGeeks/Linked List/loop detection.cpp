#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* next;
};

void push(node** head,int data)
{
	node* temp=new node();
	temp->data=data;
	temp->next=*head;
	*head=temp;
	
}

bool detect(node** head)
{
	node* slow=*head;
	node* fast=*head;
	
	while(slow!=NULL&&fast!=NULL&&fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
		
		if(slow==fast)
		return true;
	}
	return false;
	
	
}
int main()
{
	node *head;
	push(&head,10);
	push(&head,20);
	push(&head,30);
	
//	head->next->next=head;
	if(detect(&head))
	{
		cout<<"loop detected";
	}
	else
	cout<<"no loop";
	
	return 0;
	
}

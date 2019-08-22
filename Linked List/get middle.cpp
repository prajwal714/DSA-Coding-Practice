/*This is a function problem.You only need to complete the function given below*/
/* Link list Node 
struct Node {
    int data;
    Node* next;
}; */
/* Should return data of middle node. If linked list is empty, then  -1*/
#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* next;
};

void push(Node** head,int data)
{
	Node* temp=new Node();
	temp->data=data;
	temp->next=*head;
	*head=temp;
}
int getMiddle(Node *head)
{
	cout<<"Inside middle func";
    if(head==NULL)
    return -1;
    
    Node* first=head;
    Node* second=head;
    while(second!=NULL&&second->next!=NULL)
    {
    	cout<<"data:"<<second->data<<endl;
        first=first->next;
        second=second->next->next;
        
        
    }
    
    return first->data;
    
   // Your code here
}

int main()
{
	Node* head;
	push(&head,10);
	push(&head,20);
	push(&head,30);
	push(&head,40);
	push(&head,50);
	cout<<getMiddle(head);
	return 0;
}


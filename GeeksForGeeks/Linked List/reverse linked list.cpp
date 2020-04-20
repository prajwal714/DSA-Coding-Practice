#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* next;
};

void newNode(Node** head,int data)
{
	Node* temp=new Node();
	temp->data=data;
	temp->next=*head;
	*head=temp;
}
Node* rotate(Node* head, int k) {
    Node *prvHead=head,*currHead=head,*prvTail,*currTail;
    Node* temp=head;
    int count=0;
   while(temp->next!=NULL)
   {
      
       if(count==k-1)
       currTail=temp;
       if(count==k)
       currHead=temp;
       
      
       temp=temp->next;
        count++;
   }
    prvTail=temp;
   prvTail->next=head;
   currTail->next=NULL;
   
   return currHead;
    
    
    
}

void print(Node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<"->";
		head=head->next;
	}
	cout<<endl;
}
Node* reverse(Node** head)
{
	Node* prv;
	Node* curr=*head;
	Node* next=NULL;
	prv=NULL;
	
	
	
	while(curr!=NULL)
	{
		next=curr->next;
		curr->next=prv;
		prv=curr;
		curr=next;
		
		
	
	}
	
      *head=prv;
      return *head;
}

Node* recursiveRev(Node* prv,Node* curr,Node** head)
{
	if(curr->next==NULL)
	{
		*head=curr;
		curr->next=prv;
		return *head; 
	}
	
	Node* next=curr->next;
	
	curr->next=prv;
	recursiveRev(curr,next,head);
}

	int main()
{
	Node *head=NULL;
	newNode(&head,1);
	newNode(&head,2);
	newNode(&head,3);
	newNode(&head,4);
	newNode(&head,5);
	print(head);
	cout<<endl;
//	print(reverse(&head));
//	print(recursiveRev(NULL,head,&head));
	print(rotate(head,5));
	return 0;
}


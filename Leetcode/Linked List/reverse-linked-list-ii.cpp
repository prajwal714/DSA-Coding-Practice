/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
    
        ListNode* prv=NULL, *curr=head;
        
        if(head==NULL)
            return head;
        
        while(m>1)
        {
            prv=curr;
            curr=curr->next;
            
            m--;
            n--;
        }
        
        ListNode* tail=curr, *conn=prv;
        ListNode* temp=NULL;
        while(n>0)
        {
            temp=curr->next;
            curr->next=prv;
            
            prv=curr;
            curr=temp;
           n--;
        }
        if(conn==NULL)
        {
            head=prv;
        }
        else
        conn->next=prv;
        
        tail->next=curr;
        
        return head;
    }
    
};
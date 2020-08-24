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
    bool isPalindrome(ListNode* head) {
        
        if(head==NULL)
            return true;
        
        ListNode* fast=head, *slow=head;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            
            
        }
        
        if(fast)
            slow=slow->next;
        
        
        ListNode* curr=slow, *prev=NULL;
        while(curr!=NULL)
        {
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        
        while(prev)
        {
            if(head->val !=prev->val)
                return false;
            
            head=head->next;
            prev=prev->next;
        }
        
        return prev==NULL;
        
        
    }
};
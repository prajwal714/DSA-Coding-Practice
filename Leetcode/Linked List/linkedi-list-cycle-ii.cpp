/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(head==NULL)
            return head;
        ListNode* hare=head, *tortoise=head;
        
        while(hare->next!=NULL && hare->next->next!=NULL)
        {
            
            
            if(hare==NULL || hare->next==NULL)
                return NULL;
            
            tortoise=tortoise->next;
            hare=hare->next->next;
            
            if(tortoise==hare)
            {
                tortoise=head;
                while(tortoise!=hare)
                {
                    tortoise=tortoise->next;
                    hare=hare->next;
                }
                
                return hare;
            }
        }
        
        return NULL;
        
    }
};
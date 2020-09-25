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
        
        ListNode* hare=head, *tortoise=head;
        
        while(hare!=NULL && hare->next!=NULL)
        {
            hare=hare->next->next;
            tortoise=tortoise->next;
            
            if(hare==tortoise)
                break;
            
        }
        
        if(hare==NULL || hare->next==NULL)
            return NULL;
        
        tortoise=head;
        while(tortoise!=hare)
        {
            hare=hare->next;
            tortoise=tortoise->next;
        }
        
        return hare;
        
    }
};
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
    ListNode* removeElements(ListNode* head, int val) {
        
        
        ListNode* pHead=new ListNode(0);
        pHead->next=head;
        
        ListNode* curr=pHead;
        while(curr)
        {
            if(curr->next&&curr->next->val==val)
            {
                ListNode* tmp=curr->next;
                curr->next=curr->next->next;
                delete(tmp);
            }
            else
                curr=curr->next;
        }
        
        return pHead->next;
        
        
       
    }
};
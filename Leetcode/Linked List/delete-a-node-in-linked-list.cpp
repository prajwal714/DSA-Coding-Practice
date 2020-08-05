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
    void deleteNode(ListNode* node) {
        
        //swap the value with current node to next node,
        //then delete the next node;
        
        int temp=node->val;
        node->val=node->next->val;
        node->next->val=temp;
        
        ListNode* tempNode=node->next;
        node->next=node->next->next;
        
        delete(tempNode);
        
        return;
    }
};
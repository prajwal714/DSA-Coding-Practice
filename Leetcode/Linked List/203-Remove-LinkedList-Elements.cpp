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
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {

        ListNode *temp;
        if (head == NULL)
            return head;

        //we have 3 cases
        // head is the target value
        while (head != NULL && head->val == val)
        {
            temp = head;
            head = head->next;
            delete (temp);
        }

        ListNode *curr = head, *prv = NULL;

        while (curr != NULL)
        {
            if (curr->val == val)
            {
                temp = curr;
                prv->next = curr->next;
                curr = curr->next;
                delete (temp);
            }
            else
            {
                prv = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};

//recursive solution:

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {

        if (head == NULL)
            return head;

        if (head->val == val)
            return removeElements(head->next, val);

        head->next = removeElements(head->next, val);

        return head;
    }
};
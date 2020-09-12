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
struct compare{
    bool operator()(ListNode* l, ListNode* r)
    {
        return l->val>r->val;
    }
};



class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode*, vector<ListNode*>, compare>pq;
        
        for(auto l:lists)
        {
            if(l!=NULL)
                pq.push(l);
        }
        
        if(pq.empty())
            return NULL;
        
        ListNode* res=pq.top();
        pq.pop();
        
        if(res->next)
            pq.push(res->next);
        
        ListNode* tail=res;
        
        while(!pq.empty())
        {
            tail->next=pq.top();
            pq.pop();
            
            tail=tail->next;
            if(tail->next)
                pq.push(tail->next);
        }
        
        return res;
    }
};
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* resulthead,*p;
        resulthead = new ListNode(0);
        p = resulthead;
        ListNode* p1 = l1, *p2 = l2;
        if(!p1) resulthead->next = p2;
        else if(!p2) resulthead->next = p1;
        while(p1 && p2)
        {
            if(p1->val < p2->val)
            {
                p->next = p1;
                p1 = p1->next;
            }
            else
            {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        if(p1)
            p->next = p1;
        else p->next = p2;
        p = resulthead->next;
        delete resulthead;
        return p;
    }
};
/* *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *p1,*p2,*p3,*guard;
        if(!head)
            return head;
        else if(!(head->next))
            return head;
        else
        {
            p1 = head;
            p2 = head->next;
            guard = new ListNode(0);
            p3 = guard;
            p3->next = head; //here p3 be the guard
            while(p1 && p2)
            {
                p3->next = p2;
                ListNode * tmp = p2->next;
                p3 = p1;
                p2->next = p1;
                p1 = tmp;
                if(p1)
                    p2 = p1->next;
            }
            if(p1)
            {
                p3->next = p1;
            }
            else 
            {
                p3->next = nullptr;
            }
        }
        return guard->next;
    }
};
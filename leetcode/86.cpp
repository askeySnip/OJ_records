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
    ListNode* partition(ListNode* head, int x) {
        ListNode* p = head;
        while(p != NULL) {
            if(p->val >= x) {
                ListNode* t = p;
                while(t != NULL && t->val >= x) t = t->next;
                if(t == NULL) break;
                ListNode* tp = p;
                int n = tp->val;
                tp->val = t->val;
                while(tp!=t) {
                    int nn = tp->next->val;
                    tp->next->val = n;
                    n = nn;
                    tp = tp->next;
                }
            }
            p = p->next;
        }
        return head;
    }
};
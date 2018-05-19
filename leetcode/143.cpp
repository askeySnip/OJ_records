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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) return;
        // cout << head->val << endl;
        ListNode* f = head->next->next;
        ListNode* u = head;
        while(f != NULL){
            f = f->next;
            u = u->next;
        }
        ListNode* last = u->next;
        ListNode* t = head->next;
        u->next = NULL;
        head->next = last;
        last->next = t;
        reorderList(t);
    }
};
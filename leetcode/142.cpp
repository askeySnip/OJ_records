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
        if(head == NULL) return NULL;
        ListNode *s = head;
        ListNode *f = head;
        int c = 0;
        while(1){
            if(s->next != NULL) s = s->next;
            else return NULL;
            if(f->next != NULL) f = f->next;
            else return NULL;
            if(f->next != NULL) f = f->next;
            else return NULL;
            c++;
            if(f == s) break;
        }
        s = head;
        for(int i=0; i<c; i++) s = s->next;
        if(s == head) return head;
        s = head->next;
        f = head;
        for(int i=0; i<=c; i++){
            f = f->next;
        }
        while(s != f) {
            s = s->next;
            for(int i=0; i<=c; i++){
                f = f->next;
            }
        }
        return s;
    }
};
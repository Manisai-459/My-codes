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
    ListNode* rotateRight(ListNode* head, int k) {
        if( head == NULL || head->next == NULL)
            return head;
            int l = 1;
            ListNode* x = head;
            while(x->next != NULL){
                x = x->next;
                l += 1;
            }
            cout<<l;
            x->next = head;
            int p = k % l;
            p = l - p;
            x = head;
            while(p){
                x = x->next;
                p -= 1;
            }
            head = x;
            while(x->next != head)
                x = x->next;
            x->next = NULL;
    return head;
    }
};

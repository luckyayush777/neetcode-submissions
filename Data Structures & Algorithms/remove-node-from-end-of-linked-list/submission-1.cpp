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
     // 1->2->3
class Solution {
public:

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr )
            return nullptr;
        int idx_front;
        ListNode* current = head;
        int m = 0;
        while(current != nullptr){
            m++;
            current = current->next;
        }
        if(n == m)
            return head->next;
        idx_front = (m - n);
        int c_idx = 0;
        ListNode* idx = head;
        ListNode* prev = nullptr;
        while(c_idx < idx_front){
            c_idx++;
            prev = idx;
            idx = idx->next;
        }
        prev->next = idx->next;
        return head;
    }
};

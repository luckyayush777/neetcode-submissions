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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr|| head-> next == nullptr)
            return head;
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = current->next;
        while(next != nullptr){
            current->next = prev;
            prev = current;
            current = next;
            next = current->next;
        }
        current->next = prev;
        head = current;
        return head;
    }
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }//put slow at half way 
        ListNode* second = slow->next;
        slow->next = nullptr;
        ListNode* l1 = head;
        ListNode* l2 = reverseList(second);

        ListNode* currentMerge = l2;
        ListNode* nextMerge = currentMerge->next;
        ListNode* prev = l1;
        ListNode* nextNode = l1->next;
        while(currentMerge != nullptr){
            prev ->next = currentMerge;
            currentMerge->next = nextNode;
            prev = nextNode;
            nextNode = nextNode->next;
            currentMerge = nextMerge;
            if(nextMerge != nullptr)
            nextMerge = nextMerge->next;
        }
        return;
    }
};

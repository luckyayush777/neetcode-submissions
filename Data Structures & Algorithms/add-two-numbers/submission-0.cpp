class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* c1 = l1;
        ListNode* c2 = l2;
        int carry = 0;
        ListNode* prev = nullptr;
        ListNode* head = nullptr;
        while(c1 != nullptr && c2 != nullptr){
            int sum = c1->val + c2->val + carry;
            carry = sum / 10;
            ListNode* newNode = new ListNode(sum % 10);

            if(prev != nullptr){
                prev ->next = newNode;
            }else {
                head = newNode;
            }
            prev = newNode;
            c1 = c1->next;
            c2 = c2->next;
            
        }
        while(c1 != nullptr){
            int sum = c1->val + carry;
            carry = sum / 10;
            ListNode* newNode = new ListNode(sum % 10);
            prev->next = newNode;
            prev = newNode;
            c1 = c1->next;
        }
        while(c2 != nullptr){
            int sum = c2->val + carry;
            carry = sum / 10;
            ListNode* newNode = new ListNode(sum % 10);
            prev->next = newNode;
            prev = newNode;
            c2 = c2->next;
        }

        if(carry == 1){
            prev->next = new ListNode(1);
        }
        return head;
    }
};

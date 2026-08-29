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

struct Compare{
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};

class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*> , Compare> h;
        for(auto& element : lists){
            if(element != nullptr)
            h.push(element);
        }
        ListNode* head = nullptr;
        ListNode* prev = nullptr;
        while(!h.empty()){
            ListNode* smallest = h.top();
            h.pop();
            if(!head){
                head = smallest;
                prev = head;
            }else {
                prev->next = smallest;
                prev = smallest;
            }
            if(smallest->next != nullptr){
                h.push(smallest->next);
            }
        }
        return head;
    }
};

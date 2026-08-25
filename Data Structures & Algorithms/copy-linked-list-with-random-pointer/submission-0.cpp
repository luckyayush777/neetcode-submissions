class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> hm;
        hm[nullptr] = nullptr;
        Node* current = head;
        while(current != NULL){
            Node* copy = new Node(current->val);
            hm[current] = copy;
            current = current->next;
        }

        current = head;
        while(current != NULL){
            Node* copy = hm[current];
            copy->next = hm[current->next];
            copy->random = hm[current->random];
            current = current->next;
        }
        return hm[head];
    }
};